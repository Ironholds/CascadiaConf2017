library(ggplot2)
library(microbenchmark)
library(Rcpp)
library(ggthemes)

Rcpp::sourceCpp("benchmarks.cpp")

# Yoinked and heavily modified version of the autoplot method
# for microbenchmark objects
extractedplot <- function(object, title){
	
	y_min <- 0
	y_max <- 1.05 * max(object$time)

	object$ntime <- microbenchmark:::convert_to_unit(object$time, "t")
	
	plot <- ggplot(object, ggplot2::aes_string(x = "expr", y = "ntime")) +
		coord_cartesian(ylim = c(y_min, y_max)) +
		stat_ydensity() +
		scale_x_discrete() +
		scale_y_log10(name = sprintf("Time (%s)", attr(object$ntime, "unit"))) +
		ggplot2::coord_flip() +
		ggthemes::theme_economist(base_size = 12) +
		labs(title = "Testy testtest")
}

# Plotting function
bench_func <- function(functions, names, outfile){
	
	result <- microbenchmark(
		{functions[[1]]()},
		{functions[[2]]()},
		{functions[[3]]()}
	)
	levels(result$expr) <- names
	
	plot <- autoplot(result)
	
}
functions <- list(deque_pushback, std_vector_prealloc, vector_pushback)