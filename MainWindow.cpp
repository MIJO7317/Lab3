#include "MainWindow.h"
#include"BinarySearchTree.h"
#include<functional>

MainWindow::MainWindow(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	BinarySearchTree<int> bst;
	bst.Add(1);
	bst.Add(2);
	bst.Add(3);
	bst.Add(4);
	bst.Add(8);
	bst.Add(17);
	bst.Add(4);
	bool a = bst.Find(9);
	bool b = bst.Find(4);
}
