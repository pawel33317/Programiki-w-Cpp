#include"class2.hpp"
void class2::setVal(int v){
	val = v;
};
int class2::getVal() const {
	return val;
};
class2::class2(){
	val = 10;
};
