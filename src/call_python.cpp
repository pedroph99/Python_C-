#include <cstdlib>
#include <iostream>
#include <Python.h>
#include <string>
int main(int argc, char const *argv[])
{
    
    std::cout << "\t----OPTICAL NETWORKS SIMULATOR----"  << std::endl;
    /* code */
    setenv("PYTHONPATH", ".", 1);
    Py_Initialize();
    
    PyObject *name, *load_module, *func,  *callfunc, *args;
   /*
   
   
    PyObject * obj = Py_BuildValue("s", "script.py");
    FILE * fp = _Py_fopen_obj(obj, "r+");
    PyRun_SimpleFile(fp, "script.py");
    
*/

    load_module = PyUnicode_FromString("script");
    PyObject* teste = PyUnicode_FromString("3");
    // Importa o arquivo script.py como um módulo.
    PyObject * import_module = PyImport_Import(load_module);
    if(load_module){
       std::cout << "\t----FUNFOU----"  << std::endl;
    }
    else{
        std::cout << "\t----Nçao funfou----"  << std::endl;
    }

    // importa o objeto da funcao a função dentro do módulo.
    func = PyObject_GetAttrString(import_module, "simple_func");
    // chama a funcao.
    callfunc = PyObject_CallObject(func, NULL);


    //Cria classe
    PyObject *object_dataset = PyObject_GetAttrString(import_module, "dataset");
    PyObject *funcao_base = PyObject_GetAttrString(import_module, "func");
    PyObject *call_funcao_base = PyObject_CallObject(funcao_base, teste);
   
    if(call_funcao_base){
        printf("%s", "Teste");
    }
    Py_Finalize();
    return 0;
}
