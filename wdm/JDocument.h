/**
 * 抽象文档类,用来描述一个文档的属性，比如一个HTML文档，或者一个Doc文档。
 * @author jjp
 */
#pragma once

class CJDocument
{
public:
	virtual void Parse() = 0;	
};

