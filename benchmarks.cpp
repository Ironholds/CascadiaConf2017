#include <Rcpp.h>
using namespace Rcpp;

//[[Rcpp::export]]
void vector_pushback(){
	std::vector <std::string> x;
	for(unsigned int i = 0; i < 1000000; i++){
		x.push_back("This is an expansive string which we will use for testing purposes; my apologies to future readers of this code");
	}
}

// [[Rcpp::export]]
void vector_prealloc() {
	std::vector < std::string > x(1000000);
	for(unsigned int i = 0; i < 1000000; i++){
		x[i] = "This is an expansive string which we will use for testing purposes; my apologies to future readers of this code";
	}
}

//[[Rcpp::export]]
void deque_pushback(){
	std::deque < std::string > x;
	for(unsigned int i = 0; i < 1000000; i++){
		x.push_back("This is an expansive string which we will use for testing purposes; my apologies to future readers of this code");
	}
}