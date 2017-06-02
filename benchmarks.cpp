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

//[[Rcpp::export]]
void find_small(CharacterVector x, bool set_not_vec = false){
	
	if(set_not_vec){
		std::set < std::string > y;
		for(unsigned int i = 0; i < x.size(); i++){
			y.insert(Rcpp::as<std::string>(x[i]));
		}
		bool is_in;
		for(unsigned int i = 0; i < 1000000; i++){
			is_in = (y.find("small") != y.end());
		}
		if(is_in){
			return;
		}
	} else {
		std::vector < std::string > y;
		for(unsigned int i = 0; i < x.size(); i++){
			y.push_back(Rcpp::as<std::string>(x[i]));
		}
		bool is_in;
		for(unsigned int i = 0; i < 1000000; i++){
			is_in = (std::find(y.begin(), y.end(), "small") != y.end());
		}
		if(is_in){
			return;
		}
	}
	

}

void vec_insert_small(){
	
}

void set_insert_small(){
	
}

void set_find_large(){
	
}

void vec_find_large(){
	
}