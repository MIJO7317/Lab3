#include "MainWindow.h"
#include"BinarySearchTree.h"
#include<functional>
#include<complex>
//#include"vld.h"

namespace std
{
	//Перегрузка operator<< для возможности вывода в строку
	template<typename T>
	std::ostream& operator<<(std::ostream& out, const std::complex<T>& comp)
	{
		out << "(" << comp.real() << ", " << comp.imag() << ")";
		return out;
	}

	//Перегрузка у класса std::hash operator() для взятия хэша. 
	//Объединение двух хэшей происходит путем побитового сдвига и взятия операции XOR. 
	//Так же есть возможность скомбинировать два хэш значения с помощью функции has_combine из библиотеки boost. 
	template<typename T>
	struct hash<std::complex<T>>
	{
		std::size_t operator()(const std::complex<T>& comp) const
		{
			std::size_t h1 = hash<T>{}(comp.real());
			std::size_t h2 = hash<T>{}(comp.imag());
			return h1 ^ (h2 << 1);
		}
	};
}

MainWindow::MainWindow(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	BinarySearchTree<std::complex<double>> bst;
	std::complex<double> comp = { 1,2 };
	bst.SetRound(bst.LNR);
	for (size_t i = 0; i < 8; i++)
		bst.Add(std::complex<double>(rand()%100, rand() % 100));
	bst.Add(comp);
	bst.Balancing();
	auto a = bst.Find(comp);
	auto b = bst.Find((4,1));
	bst.Delete(comp);
	ui.lineEdit->setText(bst.ToString().c_str());
}
