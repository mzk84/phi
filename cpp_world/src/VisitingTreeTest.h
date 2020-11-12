#include "VisitingTree.h"



void VisitingTreeTest() {
	std::cout << "\n************************************************************\n";
	std::cout << "Visiting Tree Test\n\n";

	TreeNode1 t11, t12, t13;
	TreeNode2 t21, t22, t23, t24;
	TreeNode3 t31, t32, t33, t34, t35;
	t11.setData("11");
	t12.setData("12");
	t13.setData("13");
	t21.setData(21);
	t22.setData(22);
	t23.setData(23);
	t24.setData(24);
	t31.setData('A');
	t32.setData('B');
	t33.setData('C');
	t34.setData('D');
	t35.setData('E');

	t11.addChild(&t21);
	t11.addChild(&t22);
	t11.addChild(&t23);
	t11.addChild(&t24);

	t21.addChild(&t31);
	t22.addChild(&t32);
	t22.addChild(&t12);
	t23.addChild(&t33);
	t24.addChild(&t34);
	t24.addChild(&t35);

	t35.addChild(&t13);

	TreeVisitor1 tv1;
	TreeVisitor2 tv2;

	std::list<ITreeVisitor*> visitors;
	visitors.push_back(&tv1);
	visitors.push_back(&tv2);
	
	visitTree(&t11, &visitors);
}
