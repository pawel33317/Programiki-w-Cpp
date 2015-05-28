#include"exampleClas.hpp"
void exampleClas::setVal(double v){
	val = v;
};
double exampleClas::getVal() const {
	return val;
};
exampleClas::exampleClas(){
	val = 10.0;
};
