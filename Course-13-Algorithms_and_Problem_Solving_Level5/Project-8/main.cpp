#include "clsQueueLine.h"

int main(void)
{
    clsQueueLine PayBillsQueue("A0", 10);
    clsQueueLine SubscriptionsQueue("B0", 5);

    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();

    cout << "\nPay Bills queue info" << endl;
    PayBillsQueue.PrintQueueInfo();

    PayBillsQueue.PrintTicketsLTR();

    PayBillsQueue.PrintTicketsRTL();

    PayBillsQueue.PrintAllTickets();

    PayBillsQueue.ServeClient();

    cout << "\n\t\t Queue after serving one client: " << endl;

    PayBillsQueue.PrintQueueInfo();

    cout << "\nSubscriptions queue info" << endl;

    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();

    SubscriptionsQueue.PrintQueueInfo();

    SubscriptionsQueue.PrintTicketsLTR();

    SubscriptionsQueue.PrintTicketsRTL();

    SubscriptionsQueue.PrintAllTickets();

    SubscriptionsQueue.ServeClient();

    cout << "\n\t\t Queue after serving one client: " << endl;

    SubscriptionsQueue.PrintQueueInfo();


    return (0);
}