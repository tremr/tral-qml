//
// Created by tremr 27 jan. 2018 ã.
//
// Copyright (C) 2018
//


#include "SampleLibrary.h"
#include <iostream>


SampleLibrary::SampleLibrary()
{}

SampleLibrary::~SampleLibrary()
{
}

void SampleLibrary::say_hello() const
{
	std::cout << "!!!Hello World!!!" << std::endl;
}
