/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "catch.h"
#include "template.h"

TEST_CASE("Test Template Generate", "[templateGenerate]") {
	SECTION("one line case with one item") {
		std::string subject = "a {{ item }} sentence";
	   
		Template tmp = Template(subject);

		tmp.setValue("item", "test");
		
		REQUIRE(tmp.generateTemplate().compare("a test sentence") == 0);   
	}
	SECTION("One line case with 2 items") {
		std::string subject = "a {{ item1 }} sentence {{ item2 }} test";
	   
		Template tmp = Template(subject);

		tmp.setValue("item1", "new");
		tmp.setValue("item2", "to");
		
		REQUIRE(tmp.generateTemplate().compare("a new sentence to test") == 0);   
	}
	SECTION("Two line case with 3 items") {
		std::string subject = "a {{ item1 }} sentence {{ item2 }} test\nTest multi line with {{ item3 }}";
	   
		Template tmp = Template(subject);

		tmp.setValue("item1", "new");
		tmp.setValue("item2", "to");
		tmp.setValue("item3", "new item");
		
		REQUIRE(tmp.generateTemplate().compare("a new sentence to test\nTest multi line with new item") == 0);   
	}
	SECTION("Three line case with 5 items") {
		std::string subject = "a {{ item1 }} sentence {{ item2 }} test\nTest multi line with {{ item3 }}\n{{ item4 }} another line with {{ item5 }} items";
	   
		Template tmp = Template(subject);

		tmp.setValue("item1", "new");
		tmp.setValue("item2", "to");
		tmp.setValue("item3", "new item");
		tmp.setValue("item4", "Yet");
		tmp.setValue("item5", "two");
		
		REQUIRE(tmp.generateTemplate().compare("a new sentence to test\nTest multi line with new item\nYet another line with two items") == 0);   
	}
};