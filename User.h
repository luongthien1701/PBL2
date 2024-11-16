#pragma once
#include <string>
#include "Node.h"
class User{
	protected:
		Node* temp;
	public:
		User(Node* temp):temp(temp){
		};
		virtual void display(){
		if (temp){
			cout<<"so phong"<<temp->IdPhong;
			cout<<", Ten "<<temp->name;
			cout<<",SDT "<<temp->SDT;	
		}
	}
};

