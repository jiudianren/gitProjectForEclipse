
#include <string>
#include <iostream>
#include <iomanip>
#include <iosfwd>
#include <sstream>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>

using namespace std;



static sigset_t g_sigsetold;

int mainBB()
{

    pthread_sigmask(SIG_SETMASK, &g_sigsetold, NULL);

    struct sigaction act;
    act.sa_mask = g_sigsetold;
    act.sa_flags = SA_RESTART;


    act.sa_handler = SIG_DFL;


    sigaction(SIGHUP, &act, NULL);

    //当程序阻塞在getline的时候， 然后关闭终端，当 程序忽略SIGHUP，就会导致，程序占用cpu 过高

    for(;;)
    {

        std::ostringstream os;
        os << "================ table ""PCC_BASIC_RULE"" all columns ================";
        size_t iLength = os.str().length();
        os << "\n";
        os << std::setw(32) << "Name" << std::setw(25) << "Index" << "\n";

        std::string strEnd(iLength, '=');
        std::cout << "\n" << os.str()
                                   << "\n" << strEnd
                                   << "\nSelect column name(0:Quit, 1:Show all data):";
        std::cin.clear();
        std::string strColumnName;


        std::getline(std::cin, strColumnName);
        if( cin.bad())
        {
            std::cout << "sssss" << std::endl;
            exit(1);
        }



        if (strColumnName == "0")
        {
            return  1;
        }

    }

    return 0;
}
