#pragma once
#include<iostream>
#include<string>

class Item
{
private:
	std::string name_;
	int price_;

public:
	Item(std::string name = "None", int price = 0) : name_(name), price_(price) {}

	void PrintInfo() const 
	{
		std::cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << std::endl;
	}

	int GetPrice() const { return price_; }
};