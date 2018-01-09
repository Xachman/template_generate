/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "catch.h"
#include "template.h"

TEST_CASE("Test Template Generate", "[templateGenerate]") {
	std::string subject = "a {{ item }} sentence";
   
  	Template tmp = Template(subject);

	tmp.setValue("item", "test");
	
 	REQUIRE(tmp.generateTemplate().compare("a test sentence") == 0);   
};

TEST_CASE("Test Template Generate With 2 items", "[templateGenerate]") {
	std::string subject = "a {{ item1 }} sentence {{ item2 }} test";
   
  	Template tmp = Template(subject);

	tmp.setValue("item1", "new");
	tmp.setValue("item2", "to");
	
 	REQUIRE(tmp.generateTemplate().compare("a new sentence to test") == 0);   
};