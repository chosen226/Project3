#pragma once
#include <iostream>
using namespace std;

class dataNode
{
	
	double placeholder = -123456;

public:
	dataNode();
	dataNode(double placeholder);
	double getPlaceholder();
	void resetdataNode(double placeholder);
	void printdataNode();
};

dataNode::dataNode() {
	this->placeholder = -123456;
}

dataNode::dataNode(double placeholder) {
	this->placeholder = placeholder;
	cout << "Temp Delta: " << placeholder << endl;
}

double dataNode::getPlaceholder() {
	return placeholder;
}

void dataNode::resetdataNode(double placeholder) {
	this->placeholder = placeholder;
}

void dataNode::printdataNode() {
	cout << placeholder << endl;
}
