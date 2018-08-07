/*
 * ModelChainOfResponsible.cpp
 *
 *  Created on: 2017年7月9日
 *      Author: Lian
 */


#include "ModelChainOfResponsible.h"


/*
 * 责任链模式
 *
 * */

void mainChainOfRes()
{

	Ask ask99(99);
	Ask ask249(249);
	Ask ask599(599);

	Top3Manger top3("top3");
	Top2Manger top2("top2");
	Boss  boss("boss");

	top3.SetTopper(&top2);
	top2.SetTopper(&boss);

    top3.DealAsk(&ask99);

    top3.DealAsk(&ask249);
	top3.DealAsk(&ask599);

}

