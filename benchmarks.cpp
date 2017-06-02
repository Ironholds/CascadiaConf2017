#include <Rcpp.h>
using namespace Rcpp;
//[[Rcpp::plugins(cpp11)]]
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

//[[Rcpp::export]]
void set_find_small(){
	std::set < std::string > x{"this", "is", "a", "small", "set"};
	bool is_in = x.find("small") != x.end();
}

//[[Rcpp::export]]
void vec_find_small(){
	std::vector < std::string > x{"this", "is", "a", "small", "set"};
	bool is_in = (std::find(x.begin(), x.end(), "small") != x.end());
}

void vec_insert_small(){
	
}

void set_insert_small(){
	
}

void set_find_large(){
	
}

void vec_find_large(){
	
}