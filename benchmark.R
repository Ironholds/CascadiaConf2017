library(ggplot2)
library(microbenchmark)
library(Rcpp)
library(ggthemes)
library(readr)
Rcpp::sourceCpp("benchmarks.cpp")

# Yoinked and heavily modified version of the autoplot method
# for microbenchmark objects
extractedplot <- function(object, names, title, file){
	
	levels(object$expr) <- names
	
	y_min <- 0
	y_max <- 1.05 * max(object$time)

	object$ntime <- microbenchmark:::convert_to_unit(object$time, "t")
	
	plot <- ggplot(object, ggplot2::aes_string(x = "expr", y = "ntime")) +
		theme_tufte(base_size = 12) +
		theme(axis.text=element_text(size=12)) +
		geom_tufteboxplot() +
		coord_flip() +
		scale_x_discrete(name="") +
		scale_y_log10(name = sprintf("Time (%s)", attr(object$ntime, "unit"))) +
		labs(title = title)
	
	ggsave(file, plot)
	return(TRUE)
}

# Allocation versus appending for simple values
write_funcs <- list(deque_pushback, vector_prealloc, vector_pushback)
result <- microbenchmark(
	{write_funcs[[1]]()},
	{write_funcs[[2]]()},
	{write_funcs[[3]]()}
)
extractedplot(result, c("Deque (push back)", "Vector (preallocated)", "Vector (push back)"),
							"Vector and Deque Write Performance", "vector_write_performance.png")