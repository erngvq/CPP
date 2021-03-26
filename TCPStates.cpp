/*
 * A Simplistic TCP Finite State Machine (FSM)
 * --------------------------------------------------------------------------------------
 * Automatons, or Finite State Machines (FSM), are extremely useful to programmers when
 * it comes to software design. You will be given a simplistic version of an FSM to code
 * for a basic TCP session.
 * --------------------------------------------------------------------------------------
 * The outcome of this exercise will be to return the correct state of the TCP FSM based
 * on the array of events given.
 * --------------------------------------------------------------------------------------
 * The input will be an array of events. Your job is to traverse the FSM as determined by
 * the events, and return the proper state as a string, all caps, as shown above. If an
 * event is not applicable to the current state, your code should return "ERROR". Note
 * that the first event in each input array will be APP_PASSIVE_OPEN or APP_ACTIVE_OPEN.
 * --------------------------------------------------------------------------------------
 * Action of each event upon each state:
 *
 * CLOSED:      APP_PASSIVE_OPEN --> LISTEN
 * CLOSED:      APP_ACTIVE_OPEN  --> SYN_SENT
 * LISTEN:      RCV_SYN          --> SYN_RCVD
 * LISTEN:      APP_SEND         --> SYN_SENT
 * LISTEN:      APP_CLOSE        --> CLOSED
 * SYN_RCVD:    APP_CLOSE        --> FIN_WAIT_1
 * SYN_RCVD:    RCV_ACK          --> ESTABLISHED
 * SYN_SENT:    RCV_SYN          --> SYN_RCVD
 * SYN_SENT:    RCV_SYN_ACK      --> ESTABLISHED
 * SYN_SENT:    APP_CLOSE        --> CLOSED
 * ESTABLISHED: APP_CLOSE        --> FIN_WAIT_1
 * ESTABLISHED: RCV_FIN          --> CLOSE_WAIT
 * FIN_WAIT_1:  RCV_FIN          --> CLOSING
 * FIN_WAIT_1:  RCV_FIN_ACK      --> TIME_WAIT
 * FIN_WAIT_1:  RCV_ACK          --> FIN_WAIT_2
 * CLOSING:     RCV_ACK          --> TIME_WAIT
 * FIN_WAIT_2:  RCV_FIN          --> TIME_WAIT
 * TIME_WAIT:   APP_TIMEOUT      --> CLOSED
 * CLOSE_WAIT:  APP_CLOSE        --> LAST_ACK
 * LAST_ACK:    RCV_ACK          --> CLOSED
 * --------------------------------------------------------------------------------------
 * Examples:
 *
 * ["APP_PASSIVE_OPEN", "APP_SEND", "RCV_SYN_ACK"] => "ESTABLISHED"
 * ["APP_ACTIVE_OPEN"] => "SYN_SENT"
 * ["APP_ACTIVE_OPEN", "RCV_SYN_ACK", "APP_CLOSE", "RCV_FIN_ACK", "RCV_ACK"] => "ERROR"
 * --------------------------------------------------------------------------------------
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string traverseTCPStates(const vector<string> &events)
{
    map<pair<string, string>, string> mymap;
    string answer = "";
    
    mymap[make_pair("CLOSED", "APP_PASSIVE_OPEN")] = "LISTEN";
    mymap[make_pair("CLOSED", "APP_ACTIVE_OPEN")] = "SYN_SENT";
    mymap[make_pair("LISTEN", "RCV_SYN")] = "SYN_RCVD";
    mymap[make_pair("LISTEN", "APP_SEND")] = "SYN_SENT";
    mymap[make_pair("LISTEN", "APP_CLOSE")] = "CLOSED";
    mymap[make_pair("SYN_RCVD", "APP_CLOSE")] = "FIN_WAIT_1";
    mymap[make_pair("SYN_RCVD", "RCV_ACK")] = "ESTABLISHED";
    mymap[make_pair("SYN_SENT", "RCV_SYN")] = "SYN_RCVD";
    mymap[make_pair("SYN_SENT", "RCV_SYN_ACK")] = "ESTABLISHED";
    mymap[make_pair("SYN_SENT", "APP_CLOSE")] = "CLOSED";
    mymap[make_pair("ESTABLISHED", "APP_CLOSE")] = "FIN_WAIT_1";
    mymap[make_pair("ESTABLISHED", "RCV_FIN")] = "CLOSE_WAIT";
    mymap[make_pair("FIN_WAIT_1", "RCV_FIN")] = "CLOSING";
    mymap[make_pair("FIN_WAIT_1", "RCV_FIN_ACK")] = "TIME_WAIT";
    mymap[make_pair("FIN_WAIT_1", "RCV_ACK")] = "FIN_WAIT_2";
    mymap[make_pair("CLOSING", "RCV_ACK")] = "TIME_WAIT";
    mymap[make_pair("FIN_WAIT_2", "RCV_FIN")] = "TIME_WAIT";
    mymap[make_pair("TIME_WAIT", "APP_TIMEOUT")] = "CLOSED";
    mymap[make_pair("CLOSE_WAIT", "APP_CLOSE")] = "LAST_ACK";
    mymap[make_pair("LAST_ACK", "RCV_ACK")] = "CLOSED";
    
    for (int i = 0; i < events.size(); i++)
    {
        pair<string, string> pairKey;
        
        if (i == 0) pairKey.first = "CLOSED";
        else pairKey.first = answer;
        
        pairKey.second = events[i];
        answer = mymap[pairKey];
        if (answer == "") return "ERROR";
    }
    return answer;
}

int main()
{
    vector<string> input1{"APP_PASSIVE_OPEN", "APP_SEND", "RCV_SYN_ACK"};
    vector<string> input2{"APP_ACTIVE_OPEN"};
    vector<string> input3{"APP_ACTIVE_OPEN", "RCV_SYN_ACK", "APP_CLOSE", "RCV_FIN_ACK", "RCV_ACK"};
    vector<string> input4{"APP_ACTIVE_OPEN", "RCV_SYN_ACK", "RCV_FIN"};
    vector<string> input5{"APP_ACTIVE_OPEN", "RCV_SYN_ACK", "RCV_FIN", "APP_CLOSE"}; 

    cout << traverseTCPStates(input1) << endl; // returns "ESTABLISHED"
    cout << traverseTCPStates(input2) << endl; // returns "SYN_SENT"
    cout << traverseTCPStates(input3) << endl; // returns "ERROR"
    cout << traverseTCPStates(input4) << endl; // returns "CLOSED"
    cout << traverseTCPStates(input5) << endl; // returns "LAST_ACK"
}
