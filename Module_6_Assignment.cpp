#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>

using namespace std;


// Description		To call this function, simply pass the function name in Python that you wish to call.
// @param pName		Python function to call
// @return			None
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("python_modules.py_calculations");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}


// Description		Pass the name of the Python functino you wish to call and the string parameter you want to send
// @param proc		Name of Python function to call
// @param param		String sent to the Python function
// @return			String from Python function
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"python_modules.py_calculations");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

// Description		Pass the name of the Python functino you wish to call and the integer parameter you want to send
// @param proc		Name of Python function to call
// @param param		Integer sent to the Python function
// @return			Formated number calculation from Python function
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"python_modules.py_calculations");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


void main()
{
	int userChoice;		// Variable to select menu option
	int userNumber;		// Variable for number to calculate on

	cout << "Select from the following choices of calculations, or exit" << endl;

	// While loop to validate user input and display menu 
	do {
		cout << "1: Display a Multiplication Table" << endl;
		cout << "2: Double a value" << endl;
		cout << "3: Exit program" << endl;
		cout << "Select 1, 2, or 3" << endl;
		cin >> userChoice;

		// Selection 1: calls multiplication table from Python 
		if (userChoice == 1) {
			cout << "Enter a whole number to produce a multiplication table on:" << endl;
			cin >> userNumber;
			cout << callIntFunc("MultiplyFunction", userNumber) << endl;
			cout << endl;
		}

		// Selection 2: calls the doubled value of input from Python
		else if (userChoice == 2) {
			cout << "Enter a whole number to double:" << endl;
			cin >> userNumber;
			cout << callIntFunc("DoubleValue", userNumber) << endl;
			cout << endl;
		}

		// Selection 3: Calls exit statement from Python
		else if (userChoice == 3) {
			CallProcedure("exitStatement");
		}

		// Any other input will result in prompting user for valid entry
		else {
			cout << "Enter valid selction: 1, 2, or 3" << endl;
			cout << endl;
		}
	} while (userChoice != 3);
}