#include <iostream>
#include <queue>
#include <stack>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

class clsQueueLine
{
    string _Prefix;
    short _AvgWaitingTime = 0;
    short _TotalTickets;
    short _ServedClients = 0;
    short _ClientNumber;


    public:
    class clsTicket
    {
        short _EstTime = 0;
        short _Number = 0;
        short _WaitingClients = 0;
        string _Prefix;

        public:
            clsTicket(string Prefix, short Number, short AvgTime, short WaitingClients)
            {
                _Prefix = Prefix;
                _EstTime = AvgTime;
                _WaitingClients = WaitingClients;
                _Number = Number;
            }

            string Prefix(void)
            {
                return (_Prefix);
            }

            string FullName(void)
            {
                return (_Prefix + to_string(_Number));
            }


            short AvgServingTime(void)
            {
                return (_EstTime * _WaitingClients);
            }

            void PrintTicketInfo(void)
            {
                cout << "\n\t\t\t\t\t\t" << "-----------------------------------------" ;

                cout << "\n\t\t\t\t\t\t\t\t  " << FullName();
                cout << "\n\n\t\t\t\t\t\t\t  " << GetCurrentDateTime();
                cout << "\n\n\t\t\t\t\t\t\t  Waiting Clients: " << _WaitingClients;
                cout << "\n\n\t\t\t\t\t\t\t  Serving time in";
                cout << "\n\t\t\t\t\t\t\t   " << AvgServingTime() << " minutes." << endl;

                cout << "\n\t\t\t\t\t\t" << "-----------------------------------------" << endl;
            }

            string GetCurrentDateTime(void)
            {
                // Get current time
                time_t now = time(0);

                // Convert to local time
                tm *ltm = localtime(&now);

                // Use stringstream to format with leading zeros
                stringstream ss;

                ss << setfill('0') 
                << setw(2) << ltm->tm_mday << "/"
                << setw(2) << (ltm->tm_mon + 1) << "/"
                << (1900 + ltm->tm_year) << " - "
                << setw(2) << ltm->tm_hour << ":"
                << setw(2) << ltm->tm_min << ":"
                << setw(2) << ltm->tm_sec;

                return ss.str();
            }

    };
    
    queue <clsTicket> QueueLine;

    clsQueueLine(string Prefix, short AvgTime)
    {
        _Prefix = Prefix;
        _AvgWaitingTime = AvgTime;
        _TotalTickets = 0;
    }

    string Prefix(void)
    {
        return (_Prefix);
    }

    void IssueTicket(void)
    {
        _ClientNumber++;
        clsTicket Ticket(_Prefix, _ClientNumber, _AvgWaitingTime, WaitingClients());
        _TotalTickets++;

        QueueLine.push(Ticket);
    }

    short WaitingClients(void)
    {
        return (_TotalTickets - _ServedClients);
    }

    void ServeClient(void)
    {
        _ServedClients++;

        if (!QueueLine.empty())
        {
            QueueLine.pop();
        }
    }


    void PrintQueueInfo(void)
    {
        cout << "\n\n\t\t\t\t\t\t_____________________________________" << endl;
        cout << "\n\t\t\t\t\t\t\t     Queue  Info ";
        cout << "\n\t\t\t\t\t\t ____________________________________" << endl;

        cout << "\n\t\t\t\t\t\t\t  Prefix           = " << _Prefix;
        cout << "\n\t\t\t\t\t\t\t  Total Clients    = " << QueueLine.size();
        cout << "\n\t\t\t\t\t\t\t  Served Clients   = " << _ServedClients;
        cout << "\n\t\t\t\t\t\t\t  Waiting Clients  = " << WaitingClients();
        cout << "\n\t\t\t\t\t\t ____________________________________" << endl;
    }

    void PrintTicketsLTR(void)
    {
        queue <clsTicket> TempQueue = QueueLine;

        cout << "\n\t\t\t\t\t\t  Tickets: ";
        while (!TempQueue.empty())
        {
            cout << TempQueue.front().FullName() << " --> ";

            TempQueue.pop();
        }
        cout << endl;
    }

    void PrintTicketsRTL(void)
    {
        queue <clsTicket> TempQueue = QueueLine;
        stack <clsTicket> TicketStack;

        while (!TempQueue.empty())
        {
            TicketStack.push(TempQueue.front());

            TempQueue.pop();
        }

        cout << "\n\t\t\t\t\t\t  Tickets: ";
        while (!TicketStack.empty())
        {
            cout << TicketStack.top().FullName() << " <-- ";

            TicketStack.pop();
        }
        cout << endl;
    }

    void PrintAllTickets(void)
    {
        cout << "\n\n\n\t\t\t\t\t\t  ____________________________________" << endl;
        cout << "\n\t\t\t\t\t\t\t -------Tickets---------";
        cout << "\n\t\t\t\t\t\t  ____________________________________" << endl;
        while (!QueueLine.empty())
        {
            QueueLine.front().PrintTicketInfo();

            QueueLine.pop();
        }
        cout << endl;
    }

};