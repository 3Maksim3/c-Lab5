#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <Windows.h> 
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
    int var;
    cout << "Выберите задание(1 - лёгкий, 2 - средний, 3 - высокий) " << endl;
    cin >> var;
	switch (var)
	{
		case 1: 
		{
			//Создать тексовый файл с произвольной информацией
			//Организовать просмотр содержимого файла
			//Организовать чтение и обработку данных из файла в соответствии с индивидуальным заданием
			//Сохранить полученные результаты в новый текстовый файл

			//"Школьник"
			//Фамилия, имя, отчество, пол, национальность, рост, вес, дата рождения
			//(год,месяц,число), номер телефона, домашний адрес(почтовый индекс,
			//страна, область, район, город, улица, дом, квартира), школа, класс
			//Вывести сведения про всех учеников пятого класса
			
			fstream fs;
			char value,value2;
			string schoolboy0;
			string schoolboy1 = "Комаров Павел Петрович, мужской, украинец, 140, 40, 03.04.09, +380хххххх543, 54000, Украина, Николаев, Адмирала Макарова, 45 , 3, Николаевская общеобразовательная школа 1-3 ступеней №48, 5";
			string schoolboy2 = "Трублаевский Харитон Станиславович, мужской, украинец, 139, 45, 24.11.09, +380хххххх432, 54000, Украина, Николаев, Большая Морская, 27, 68, Николаевская общеобразовательная школа 1-3 ступеней №48, 5. ";
			string schoolboy3 = "Жуков Шарль Брониславович, мужской, украинец, 142, 43, 12.05.09, +380хххххх002, 54000, Украина, Николаев, Лягина, 106, 665, Николаевская общеобразовательная школа 1-3 ступеней №48, 5.";
			string schoolboy4 = "Лапина Ника Алексеевна, женский, украинка, 140, 39, 06.10.09, +380хххххх050, 54000, Украина, Николаев, Пушкинская, 222, 104, Николаевская общеобразовательная школа 1-3 ступеней №48, 5.";
			string schoolboy5 = "Горобчук Ульяна Артёмовна, женский, украинка, 145, 42, 01.01.09, +380хххххх871, 54000, Украина, Николаев, Фалеевская, 2, 501, Николаевская общеобразовательная школа 1-3 ступеней №48, 5.";
			
			fs.open("myFile.txt", fstream::in | fstream::out | fstream::app);
			if (!fs.is_open())
				cout << "Ошибка открытия файла!" << endl;
			else
			{
				fs << schoolboy1 << "\n" << schoolboy2 << "\n" << schoolboy3 << "\n" << schoolboy4 << "\n" << schoolboy5 << endl;

				fs.close();
				fs.open("myFile.txt", fstream::in | fstream::out | fstream::app);

				cout << "Содержимое Файла:" << endl;
				cout << endl;
				char ch;
				while (fs.get(ch))
					cout << ch;

				cout << endl;

				cout << "Хотите добавить информацию о другом 5 - класснике?(введите Y(англ))" << endl;
				cin >> value2;
				if (value2 == 'y' || value2 == 'Y')
				{
					cout << "Доп://Фамилия,имя,отчество,пол,национальность,рост,вес,дата рождения(год,месяц,число),номер телефона,домашний адрес(почтовый индекс,страна,область,район,город,улица,дом,квартира),школа,класс" << endl;
					fstream fs2;
					fs2.open("NewFile.txt", fstream::in | fstream::out | fstream::app);
					fs2 << schoolboy1 << "\n" << schoolboy2 << "\n" << schoolboy3 << "\n" << schoolboy4 << "\n" << schoolboy5 << endl;
					
					SetConsoleCP(1251);
					cin.ignore();
					getline(cin, schoolboy0);
					fs2 << schoolboy0;
					SetConsoleCP(866);
					
					fs2.close();
				}
				else
					cout << "Нет? Тогда до скорого..." << endl;
				}
				fs.close();
				break;
			}
		case 2:
		{
			//Создать текстовый файл в текстовом редакторе 
			//Организовать просмотрт содержимого файла и выполнения действий в соответствии с условие индивидуального задания
			//Обеспечить сохранение всех полученых результатов в новый файл

			//Дан файл f, компоненты которого являются целыми числами
			//Ни один из компонентов файла не равен нулю
			//Файл f содержит столько же отрицательных чисел, сколько и положительных
			//Используя вспомогательный файл h, переписать компоненты файла f в файл g так, чтобы в файле g сначала шли положительные, потом отрицательные числа
			fstream fs1, fs2, fs3;
			string frstfile = "F_File.txt";
			string scndfile = "H_File.txt";
			string thtdfile = "G_File.txt";

			fs1.open(frstfile, fstream::in | fstream::out | fstream::app);
			if (!fs1.is_open())
				cout << "Ошибка открытия файла F!" << endl;
			else
			{
				fs2.open(scndfile, fstream::in | fstream::out | fstream::app);
				if (!fs2.is_open())
					cout << "Ошибка открытия файла H!" << endl;
				else
				{
					fs3.open(thtdfile, fstream::in | fstream::out | fstream::app);
					if (!fs3.is_open())
						cout << "Ошибка открытия файла G!" << endl;
					else
					{
						const int N = 20;
						int massive[N];
						for (int i = 0; i < N / 2; i++)
						{
							massive[i + i] = 1 + rand() % 30;
							massive[i + 1 + i] = 1 - rand() % 30 - 30;
						}

						for (int i = 0; i < N; i++)
							fs1 << massive[i] << " ";

						for (int i = 0; i < N; i++)
							if (massive[i] > 0)
								fs2 << massive[i] << " ";

						for (int i = 0; i < N; i++)
							if (massive[i] < 0)
								fs2 << massive[i] << " ";

						fs2.close();
						fs2.open(scndfile, fstream::in | fstream::out | fstream::app);

						int massive1[N];
						for (int i = 0; i < N; i++)
							fs2 >> massive1[i];

						for(int i = 0; i < N; i++)
							fs3 << massive1[i] << " ";

						cout << "Все прошло успешно!" << endl;
					}
				}
			}
			fs1.close();
			fs2.close();
			fs3.close();

			break;
		}
		case 3:
		{
			//Представленное задание оформить в виде текстового файла

			//В первом файле хранится k матриц размерности m x n, во втором l матриц размерности m x n
			//Убрать из файла, в котором больше матриц, лишние матрици в трейтий файл
			//Вывести на экран содержимое первого, второго, третьего файла
			
			fstream fs1, fs2, fs3;
			string frstfile = "First_File.txt";
			string scndfile = "Second_File.txt";
			string thtdfile = "third_File.txt";

			const int k = 7, m1 = 6, n1 = 5, l = 6, m2 = 6, n2 = 5;
			int massive1[k][m1][n1] , massive2[l][m2][n2];
			fs1.open(frstfile, fstream::in | fstream::out | fstream::app);
			if (!fs1.is_open())
				cout << "Ошибка открытия 1-го файла!" << endl;
			else
			{
				fs2.open(scndfile, fstream::in | fstream::out | fstream::app);
				if (!fs2.is_open())
					cout << "Ошибка открытия 2-го файла!" << endl;
				else
				{
					fs3.open(thtdfile, fstream::in | fstream::out | fstream::app);
					if (!fs3.is_open())
						cout << "Ошибка открытия 3-го файла!" << endl;
					else
					{
						for (int z = 0; z < k; z++)
							for (int i = 0; i < m1; i++)
								for (int j = 0; j < n1; j++)
									massive1[z][i][j] = rand() % 10 - 10;
						
						for (int z = 0; z < l; z++)
							for (int i = 0; i < m2; i++)
								for (int j = 0; j < n2; j++)
									massive2[z][i][j] = 10 - rand() % 20 - 20;

						for (int z = 0; z < k; z++)
						{
							for (int i = 0; i < m1; i++)
							{
								for (int j = 0; j < n1; j++)
								{
									fs1 << setw(3) << massive1[z][i][j] << " ";
								}
								fs1 << endl;
							}
							fs1 << endl;
						}

						for (int z = 0; z < l; z++)
						{
							for (int i = 0; i < m2; i++)
							{
								for (int j = 0; j < n2; j++)
								{
									fs2 << setw(3) << massive2[z][i][j] << " ";
								}
								fs2 << endl;
							}
							fs2 << endl;
						}

						if (k > l)
						{
							for (int z = k; z > k - (k - l); z--)
							{
								for (int i = 0; i < m1; i++)
								{
									for (int j = 0; j < n1; j++)
									{
										fs3 << setw(3) << massive1[z - 1][i][j] << " ";
									}
									fs3 << endl;
								}
								fs3 << endl;
							}
						}
						else
						{
							for (int z = l; z > l - (l - k); z--)
							{
								for (int i = 0; i < m2; i++)
								{
									for (int j = 0; j < n2; j++)
									{
										fs3 << setw(3) << massive2[z - 1][i][j] << " ";
									}
									fs3 << endl;
								}
								fs3 << endl;
							}
						}

						fs1.close();
						fs1.open(frstfile, fstream::in | fstream::out | fstream::app);

						cout << "Содержимое 1-го файла:" << endl;
						char ch1;
						while (fs1.get(ch1))
							cout << ch1;

						cout << endl << endl;

						fs2.close();
						fs2.open(scndfile, fstream::in | fstream::out | fstream::app);

						cout << "Содержимое 2-го файла:" << endl;
						char ch2;
						while (fs2.get(ch2))
							cout << ch2;

						cout << endl << endl;

						fs3.close();
						fs3.open(thtdfile, fstream::in | fstream::out | fstream::app);

						cout << "Содержимое 3-го файла:" << endl;
						char ch3;
						while (fs3.get(ch3))
							cout << ch3;
					}
				}
			}
			fs1.close();
			fs2.close();
			fs3.close();

			break;
		}
		default:
		{
			cout << "Введите заново!" << endl;
		}
	}

	return 0;
}

