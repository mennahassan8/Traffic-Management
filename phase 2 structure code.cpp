#include <iostream>
#include <fstream>
#include <sstream>



using namespace std;





class TrafficControlCenter;





class Node
{
public:
    int data;
    Node* next;
    int priority;
    Node()
    {
        data = 0;
        next = NULL;
        priority = 0;
    }
};

class Linkedlist
{
public:
    Node* head;
    Linkedlist()
    {
        head = NULL;
    }

    Node* getHead()
    {
        return head;
    }

    bool isempty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insertfirst(int newitem)
    {
        Node* newnode = new Node();
        newnode->data = newitem;
        newnode->next = head;
        head = newnode;
    }

    void append(int newvalue)
    {
        if (isempty())
        {
            insertfirst(newvalue);
        }
        else
        {
            Node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            Node* newnode = new Node();
            newnode->data = newvalue;
            newnode->next = NULL;
            temp->next = newnode;
        }
    }

    void display()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Queue
{
public:
    Node* front;
    Node* rear;
    Queue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int item)
    {
        Node* newnode = new Node();
        newnode->data = item;
        if (isEmpty())
        {
            front = rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }
        Node* delptr = front;
        int x = delptr->data;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete delptr;
        return x;
    }

    bool isFound(int item)
    {
        Node* temp = front;
        while (temp != NULL)
        {
            if (temp->data == item)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void display()
    {
        Node* temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool removeByID(int id)
    {
        if (isEmpty())
        {
            return false;
        }
        if (front->data == id)
        {
            dequeue();
            return true;
        }
        Node* current = front;
        while (current->next != NULL)
        {
            if (current->next->data == id)
            {
                Node* del = current->next;
                current->next = del->next;
                if (del == rear)
                {
                    rear = current;
                }
                delete del;
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

class Priority_node
{
public:
    int data;
    Priority_node* next;
    int priority;
    Priority_node()
    {
        data = 0;
        next = NULL;
        priority = 0;
    }
};

class Priorityqueue
{
public:
    Priority_node* front;
    Priority_node* rear;
    Priorityqueue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int item, int priority)
    {
        Priority_node* newnode = new Priority_node();
        newnode->data = item;
        newnode->priority = priority;
        newnode->next = NULL;

        if (isEmpty())
        {
            front = rear = newnode;
            return;
        }
        if (priority < front->priority)
        {
            newnode->next = front;
            front = newnode;
        }
        else
        {
            Priority_node* temp = front;
            while (temp->next != NULL && temp->next->priority <= priority)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
            if (newnode->next == NULL)
            {
                rear = newnode;
            }
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }
        Priority_node* delptr = front;
        int x = delptr->data;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete delptr;
        return x;
    }

    void display()
    {
        Priority_node* temp = front;
        while (temp != NULL)
        {
            cout << "[" << temp->data << "|P" << temp->priority << "] ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool removeByID(int id)
    {
        if (isEmpty())
        {
            return false;
        }
        if (front->data == id)
        {
            dequeue();
            return true;
        }
        Priority_node* current = front;
        while (current->next != NULL)
        {
            if (current->next->data == id)
            {
                Priority_node* del = current->next;
                current->next = del->next;
                if (del == rear)
                {
                    rear = current;
                }
                delete del;
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

class Stack
{
public:
    Node* top;
    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        Node* ptr = new Node();
        if (ptr == NULL)
        {
            delete ptr;
            return true;
        }
        delete ptr;
        return false;
    }

    void push(int item)
    {
        Node* newnode = new Node();
        newnode->data = item;
        newnode->next = top;
        top = newnode;
    }

    int pop()
    {
        if (isEmpty())
        {
            return -1;
        }
        Node* del = top;
        int value = top->data;
        top = top->next;
        delete del;
        return value;
    }
};

class Vehicle
{
protected:
    int id;
    string type;
    int priority;
    double arrival_time;
    int currentIntersection_ID;

public:
    Vehicle(int vid, string vtype, int vpriority, double varrival)
    {
        id = vid;
        type = vtype;
        priority = vpriority;
        arrival_time = varrival;
        currentIntersection_ID = -1;
    }

    int getId()
    {
        return id;
    }
    string getType()
    {
        return type;
    }
    int getPriority()
    {
        return priority;
    }
    void setIntersection(int i)
    {
        currentIntersection_ID = i;
    }
    int getcurrentIntersection_ID()
    {
        return currentIntersection_ID;
    }

    virtual void display()
    {
        cout << "ID=" << id << " Type=" << type << endl;
    }
};

class Emergency : public Vehicle
{
public:
    Emergency(int eid, double earrival) : Vehicle(eid, "EV", 1, earrival)
    {
    }
    void display() override
    {
        cout << id << " emergency has the top priority" << endl;
    }
};
class Public_transportation : public Vehicle
{
public:
    Public_transportation(int pid, double parrival) : Vehicle(pid, "PT", 2, parrival)
    {
    }
    void display() override
    {
        cout << id << " public transportation has the highest priority" << endl;
    }
};
class Car : public Vehicle
{
public:
    Car(int cid, double carrival) : Vehicle(cid, "NC", 3, carrival)
    {
    }
    void display() override
    {
        cout << id << " normal car has normal priority" << endl;
    }
};
class Frieght_veichle : public Vehicle
{
public:
    Frieght_veichle(int fid, double farrival) : Vehicle(fid, "FV", 4, farrival)
    {
    }
    void display() override
    {
        cout << id << " truck has low priority" << endl;
    }
};

class Lane
{
private:
    int laneID;
    bool blocked;
    Priorityqueue lanequeue;

public:
    Lane(int lId)
    {
        laneID = lId;
        blocked = false;
    }

    int getLaneid()
    {
        return laneID;
    }
    bool getblocked()
    {
        return blocked;
    }

    void addVehicle(int vehicle_id, int priority = 3)
    {
        if (!blocked)
        {
            lanequeue.enqueue(vehicle_id, priority);
        }
    }

    bool lane_isEmpty()
    {
        return lanequeue.isEmpty();
    }
    void display_vehicles()
    {
        lanequeue.display();
    }

    int peekPriority()
    {
        if (lanequeue.isEmpty())
        {
            return 3;
        }
        return lanequeue.front->priority;
    }

    int getthe_nextvehicle()
    {
        if (blocked)
        {
            return -1;
        }
        return lanequeue.dequeue();
    }
    bool removeVehicle(int vid)
    {
        return lanequeue.removeByID(vid);
    }
};

class LaneNODE
{
public:
    Lane* data;
    LaneNODE* next;
};

class Lane_list
{
public:
    LaneNODE* head;
    Lane_list()
    {
        head = NULL;
    }

    void append(Lane* newvalue)
    {
        LaneNODE* newnode = new LaneNODE();
        newnode->data = newvalue;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            LaneNODE* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
};

class Intersection
{
private:
    int ID;
    int Lanes;
    bool is_blocked;
    Lane_list lane;

public:
    Intersection(int id, int lanes_count)
    {
        ID = id;
        Lanes = lanes_count;
        is_blocked = false;
        for (int i = 1; i <= Lanes; i++)
        {
            Lane* l = new Lane(i);
            lane.append(l);
        }
    }

    int getID() const
    {
        return ID;
    }
    bool isBlocked()
    {
        return is_blocked;
    }
    void setBlocked(bool b)
    {
        is_blocked = b;
    }

    Lane* getlane(int laneid)
    {
        LaneNODE* temp = lane.head;
        while (temp != NULL)
        {
            if (temp->data->getLaneid() == laneid)
            {
                return temp->data;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void addVehicle(Vehicle* v)
    {
        string type = v->getType();
        int target_lane = 3;
        if (type == "EV")
        {
            target_lane = 1;
        }
        else if (type == "PT")
        {
            target_lane = 2;
        }
        else if (type == "NC")
        {
            target_lane = 3;
        }
        else if (type == "FV")
        {
            target_lane = 4;
        }

        v->setIntersection(ID);

        Lane* l = getlane(target_lane);
        if (l != NULL)
        {
            l->addVehicle(v->getId(), v->getPriority());
        }
    }

    void displayStatus()
    {
        cout << "   Intersection " << ID;
        if (is_blocked)
        {
            cout << " [BLOCKED]";
        }
        else
        {
            cout << " [ACTIVE]";
        }
        cout << endl;
        for (int i = 1; i <= Lanes; i++)
        {
            cout << "     Lane " << i << ": ";
            Lane* l = getlane(i);
            if (l)
            {
                l->display_vehicles();
            }
            cout << endl;
        }
    }

    bool removeVehicle(int vid, int priority)
    {
        LaneNODE* temp = lane.head;
        while (temp != NULL)
        {
            if (temp->data->removeVehicle(vid))
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

class TrafficControlCenter
{
public:
    Intersection** intersections;
    int intersectionCount;


    Queue* EVqueue = new Queue();
    Queue* PTqueue = new Queue();
    Queue* FVqueue = new Queue();
    Queue* NCqueue = new Queue();



    TrafficControlCenter()
    {
        intersections = NULL;
        intersectionCount = 0;
    }

    void setIntersections(Intersection** ints, int count)
    {
        intersections = ints;
        intersectionCount = count;
    }

    Intersection* getIntersection(int id)
    {
        if (id > 0 && id <= intersectionCount)
        {
            return intersections[id];
        }
        return NULL;
    }

    Intersection** getAllIntersections()
    {
        return intersections;
    }


    void simulateStep() {
        for (int i = 1; i <= intersectionCount; i++) {
            if (intersections[i] != nullptr) {
            }
        }
    }


    void displayFullSystem()
    {
        for (int i = 1; i <= intersectionCount; i++)
        {
            intersections[i]->displayStatus();
        }
       
    }


};

class RerouteManager
{
private:
    Linkedlist* roadMap;
    int numIntersections;
    bool isEnabled;

public:
    RerouteManager(int n, bool enabled)
    {
        numIntersections = n;
        isEnabled = enabled;
        roadMap = new Linkedlist[numIntersections + 1];
    }

    void addConnection(int fromID, int toID)
    {
        roadMap[fromID].append(toID);
    }

    int findTargetIntersection(int currentID, Intersection* allIntersections[])
    {
        if (!isEnabled)
        {
            return -1;
        }
        Node* neighbor = roadMap[currentID].getHead();

        while (neighbor != NULL)
        {
            int targetID = neighbor->data;
            if (allIntersections[targetID] != NULL && !allIntersections[targetID]->isBlocked())
            {
                return targetID;
            }
            neighbor = neighbor->next;
        }
        return -1;
    }
};

class Event
{
protected:
    int eventTime;
    int intersectionID;
public:
    Event(int time, int intID) : eventTime(time), intersectionID(intID)
    {
    }
    virtual void execute(TrafficControlCenter* tcc) = 0;
    virtual int getPriority() = 0;
    int getTime()
    {
        return eventTime;
    }
};

class ArrivalEvent : public Event
{
private:
    Vehicle* vehicle;
public:
    ArrivalEvent(int time, int intID, Vehicle* v) : Event(time, intID), vehicle(v)
    {
    }
    void execute(TrafficControlCenter* tcc) override
    {
        Intersection* inter = tcc->getIntersection(intersectionID);
        if (inter)
        {
            inter->addVehicle(vehicle);
        }
    }
    int getPriority() override
    {
        return 4;
    }
};

class AccidentEvent : public Event
{
protected:
    int laneID;
    int duration;
    RerouteManager* rerouter;

public:
    AccidentEvent(int time, int intersection, int lane, int dur, RerouteManager* r)
        : Event(time, intersection), laneID(lane), duration(dur), rerouter(r)
    {
    }

    void execute(TrafficControlCenter* tcc) override
    {
        cout << "\nAccident at Int " << intersectionID << " Lane " << laneID << endl;
        Intersection* currentInt = tcc->getIntersection(intersectionID);
        Lane* blockedLane = currentInt->getlane(laneID);
        int targetID = rerouter->findTargetIntersection(intersectionID, tcc->getAllIntersections());

        if (targetID != -1)
        {
            Intersection* targetInt = tcc->getIntersection(targetID);
            cout << "Rerouting Lane " << laneID << " vehicles to Int " << targetID << endl;
            while (!blockedLane->lane_isEmpty())
            {
                int p = blockedLane->peekPriority();
                int vid = blockedLane->getthe_nextvehicle();
                Lane* targetLane = targetInt->getlane(laneID);
                if (targetLane)
                {
                    targetLane->addVehicle(vid, p);
                }
            }
        }
    }
    int getPriority() override
    {
        return 3;
    }
};

class RoadClosureEvent : public Event
{
protected:
    int duration;
    RerouteManager* rerouter;

public:
    RoadClosureEvent(int time, int intersection, int dur, RerouteManager* r)
        : Event(time, intersection), duration(dur), rerouter(r)
    {
    }

    void execute(TrafficControlCenter* tcc) override
    {
        cout << "\n EVENT: Road Closure at Int " << intersectionID << endl;
        Intersection* currentInt = tcc->getIntersection(intersectionID);
        currentInt->setBlocked(true);
        int targetID = rerouter->findTargetIntersection(intersectionID, tcc->getAllIntersections());
        if (targetID != -1)
        {
            Intersection* targetInt = tcc->getIntersection(targetID);
            cout << " Rerouting ALL vehicles to Int " << targetID << endl;
            for (int i = 1; i <= 4; i++)
            {
                Lane* currentLane = currentInt->getlane(i);
                while (currentLane != NULL && !currentLane->lane_isEmpty())
                {
                    int p = currentLane->peekPriority();
                    int vid = currentLane->getthe_nextvehicle();
                    Lane* targetLane = targetInt->getlane(i);
                    if (targetLane)
                    {
                        targetLane->addVehicle(vid, p);
                    }
                }
            }
        }
    }
    int getPriority() override
    {
        return 3;
    }
};

class CancellationEvent : public Event
{
protected:
    int time;
    int VId;
public:
    CancellationEvent(int t, int id) : Event(t, -1), time(t), VId(id)
    {
    }

    int getPriority() override
    {
        return 1;
    }

    void execute(TrafficControlCenter* tcc) override
    {
        cout << "Executing Cancellation for Vehicle " << VId << endl;
        Intersection** allIntersections = tcc->getAllIntersections();
        for (int i = 1; i <= tcc->intersectionCount; i++)
        {
            Intersection* currentInt = allIntersections[i];
            if (currentInt->removeVehicle(VId, 0))
            {
                cout << "Vehicle " << VId << " removed." << endl;
                break;
            }
        }
    }
};

class EventNode
{
public:
    Event* data;
    EventNode* next;
    EventNode(Event* e) : data(e), next(NULL)
    {
    }
};

class EventQueue
{
private:
    EventNode* head;
public:
    EventQueue()
    {
        head = NULL;
    }
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(Event* newEvent)
    {
        EventNode* newNode = new EventNode(newEvent);
        if (head == NULL || shouldComeBefore(newEvent, head->data))
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            EventNode* current = head;
            while (current->next != NULL && !shouldComeBefore(newEvent, current->next->data))
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    bool shouldComeBefore(Event* a, Event* b)
    {
        if (a->getTime() != b->getTime())
        {
            return a->getTime() < b->getTime();
        }
        return a->getPriority() < b->getPriority();
    }

    int peekTime()
    {
        if (isEmpty())
        {
            return -1;
        }
        return head->data->getTime();
    }

    Event* dequeue()
    {
        if (isEmpty())
        {
            return NULL;
        }
        EventNode* temp = head;
        Event* e = temp->data;
        head = head->next;
        delete temp;
        return e;
    }
};




class UI {
public:
    int num_intersections;
    int switch_cost;
    int auto_threshold;
    int cancel_threshold;
    string flag;
    int num_events;
    string filename;
    Linkedlist* intersection_connections;
    string* events;
    string m;



    int total_vehicles;
    int total_EV;
    int total_PT;
    int total_NC;
    int total_FV;
    int canceled_count;
    int promoted_count;



    UI() {
        num_intersections = 0;
        switch_cost = 0;
        auto_threshold = 0;
        cancel_threshold = 0;
        flag = "OFF";
        num_events = 0;
        filename = "";
        intersection_connections = NULL;
        events = NULL;
        m = "silent";
        total_vehicles = 0;
        total_EV = 0;
        total_PT = 0;
        total_NC = 0;
        total_FV = 0;
        canceled_count = 0;
        promoted_count = 0;
    }



    void selectSimulationMode() {

        int num;
        cout << "for interactive mode, enter 1" << endl;
        cout << "for step by step mode, enter 2" << endl;
        cout << "for silent mode, enter 3" << endl;


        cin >> num;

        if (num == 1) {
            m = "interactive";

        }
        else if (num == 2) {
            m = "step";

        }

        else if (num == 3) {

            m = "silent";
            

        }

        else {
            cout << "Only 1, 2, or 3 allowed, ";
            m = "silent";
        }

    }


   

    void displayTimestep(int time, TrafficControlCenter* tcc) {
        if (m == "silent") return; 

        if (m == "interactive") {
            cout << "press enter";
          
        }

        else if (m == "step") {

         
        }


    }


    void printStatistics() {
        cout << "Total Vehicles: " << total_vehicles << endl;
        cout << "Total EV: " << total_EV << endl;
        cout << "Total PT: " << total_PT << endl;
        cout << "Total NC: " << total_NC << endl;
        cout << "Total FV: " << total_FV << endl;
        cout << "Canceled vehicles: " << canceled_count << endl;
        cout << "Promoted vehicles: " << promoted_count << endl;

    }



    void Simulation(TrafficControlCenter& TCC, EventQueue& eventManager, int maxTimesteps) {
        int currentTimestep = 1;
        cout << "system start";

        while (!eventManager.isEmpty()) {
            cout << "\n Time: " << currentTimestep << " :" << endl;
            while (!eventManager.isEmpty() && eventManager.peekTime() == currentTimestep) {
                Event* e = eventManager.dequeue();
                e->execute(&TCC);
            }
            TCC.simulateStep();
            TCC.displayFullSystem();
            currentTimestep++;
        }
        cout << "system end";
    }




    bool getFile() {
        cout << "Enter filename: ";
        cin >> filename;

        ifstream file(filename);

        if (!file.is_open()) {
            cout << "Error: Cannot open file" << endl;
            
        }

        file >> num_intersections;
        cout << num_intersections << endl;

        file >> switch_cost;
        cout << switch_cost << endl;

        file >> auto_threshold;
        cout << auto_threshold << endl;

        file >> cancel_threshold;
        cout << cancel_threshold << endl;

        file >> flag;
        cout << flag << endl;

        string connections;
        file >> connections;
        cout << connections << endl;

        intersection_connections = new Linkedlist[num_intersections+1];

        for (int i = 0; i < num_intersections; i++) {
            int intersection_id;
            char colon;
            file >> intersection_id >> colon;
            cout << intersection_id << ": ";

            int connected_intersection;
            while (file.peek() != '\n') {
                file >> connected_intersection;
                intersection_connections[intersection_id].append(connected_intersection);
                cout << connected_intersection << " ";
            }
            cout << endl;
        }

        file >> num_events;
        cout << num_events << endl;

        events = new string[num_events];

        
        

        for (int i = 0; i < num_events; i++) {
            string line;
            getline(file, line);
            events[i] = line;

           
            stringstream ss(line);
            string event_type;
            ss >> event_type;

            if (event_type == "A") {
                string t;
                int at, id, inter, lane, xd;

                ss >> t >> at >> id >> inter >> lane >> xd;

                if (t == "EV") {
                    total_EV = total_EV + 1;
                    cout << "Event " << i + 1 << ": EV " << id << " at time " << at << endl;
                }
                else if (t == "PT") {
                    total_PT = total_PT + 1;
                    cout << "Event " << i + 1 << ": PT " << id << " at time " << at << endl;
                }
                else if (t == "NC") {
                    total_NC = total_NC + 1;
                    cout << "Event " << i + 1 << ": NC " << id << " at time " << at << endl;
                }
                else if (t == "FV") {
                    total_FV = total_FV + 1;
                    cout << "Event " << i + 1 << ": FV " << id << " at time " << at << endl;
                }
            }
            else if (event_type == "X") {
                int at, id;
                ss >> at >> id;

                canceled_count = canceled_count + 1;
                cout << "Event " << i + 1 << ": Cancel " << id << " at time " << at << endl;
            }
            else if (event_type == "P") {
                int at, id;
                ss >> at >> id;

                promoted_count++;
                cout << "Event " << i + 1 << ": Promote " << id << " at time " << at << endl;
            }
            else if (event_type == "ACC") {
                int at, inter, lane, dur;
                ss >> at >> inter >> lane >> dur;

                cout << "Event " << i + 1 << ": Accident at " << inter << " lane " << lane << " for " << dur << " second" << endl;
            }
            else if (event_type == "RC") {
                int at, inter, dur;
                ss >> at >> inter >> dur;

                cout << "Event " << i + 1 << ": Road closure at " << inter << " for " << dur << " second" << endl;
            }
            else {
                cout << "Event " << i + 1 << ": Unknown event" << line << endl;
            }

            total_vehicles = total_EV + total_PT + total_NC + total_FV;
        }

        file.close();
        return true;
    }





    void writeOutputFile() {
        string output_file;
        cout << "Enter output file name: ";
        cin >> output_file;

        ofstream outFile(output_file);

        if (!outFile.is_open()) {
            cout << "Error: Cannot create output file" << endl;
            return;
        }

        outFile << "CT ID AT WT XD TYPE INT LN" << endl;

        string* vehicleTypes = new string[100];
        int* vehicleAT = new int[100];
        int* vehicleID = new int[100];
        int* vehicleINT = new int[100];
        int* vehicleLN = new int[100];
        int* vehicleXD = new int[100];
        int* vehicleWT = new int[100];
        int* vehicleCT = new int[100];
        bool* vehicleCanceled = new bool[100];
        bool* vehiclePromoted = new bool[100];

        for (int i = 0; i < 100; i++) {
            vehicleCanceled[i] = false;
            vehiclePromoted[i] = false;
            vehicleCT[i] = -1;
        }

        int vehicleCount = 0;
        int canceledVehicles = 0;
        int promotedVehicles = 0;

        for (int i = 0; i < num_events; i++) {
            if (events[i].empty()) continue;

            stringstream ss(events[i]);
            string event_type;
            ss >> event_type;

            if (event_type == "A") {
                string type;
                int at, id, inter, lane, xd;
                ss >> type >> at >> id >> inter >> lane >> xd;

                vehicleTypes[vehicleCount] = type;
                vehicleAT[vehicleCount] = at;
                vehicleID[vehicleCount] = id;
                vehicleINT[vehicleCount] = inter;
                vehicleLN[vehicleCount] = lane;
                vehicleXD[vehicleCount] = xd;

                if (type == "EV") {
                    vehicleWT[vehicleCount] = 1;
                    vehicleCT[vehicleCount] = at + xd + 1;
                }
                else if (type == "PT") {
                    vehicleWT[vehicleCount] = 3;
                    vehicleCT[vehicleCount] = at + xd + 3;
                }
                else if (type == "NC") {
                    vehicleWT[vehicleCount] = 5;
                    vehicleCT[vehicleCount] = at + xd + 5;
                }
                else if (type == "FV") {
                    vehicleWT[vehicleCount] = 4;
                    vehicleCT[vehicleCount] = at + xd + 4;
                }

                vehicleCount++;
            }
        }

        for (int i = 0; i < num_events; i++) {
            if (events[i].empty()) continue;

            stringstream ss(events[i]);
            string event_type;
            ss >> event_type;

            if (event_type == "X") {
                int at, id;
                ss >> at >> id;

                for (int j = 0; j < vehicleCount; j++) {
                    if (vehicleID[j] == id) {
                        vehicleCanceled[j] = true;
                        vehicleCT[j] = -1;
                        canceledVehicles = canceledVehicles+1;
                        break;
                    }
                }
            }
            else if (event_type == "P") {
                int at, id;
                ss >> at >> id;

                for (int j = 0; j < vehicleCount; j++) {
                    if (vehicleID[j] == id && vehicleTypes[j] == "PT") {
                        vehiclePromoted[j] = true;
                        vehicleTypes[j] = "EV";
                        vehicleWT[j] = 1;
                        vehicleCT[j] = at + vehicleXD[j] + 1;
                        promotedVehicles= promotedVehicles+1;
                        break;
                    }
                }
            }
        }

      

        int totalWT = 0;
        int totalXD = 0;
        int totalEV_WT = 0, totalPT_WT = 0, totalNC_WT = 0, totalFV_WT = 0;
        int totalEV_XD = 0, totalPT_XD = 0, totalNC_XD = 0, totalFV_XD = 0;
        int evCount = 0, ptCount = 0, ncCount = 0, fvCount = 0;

        for (int i = 0; i < vehicleCount; i++) {
            if (!vehicleCanceled[i]) {
                totalWT = totalWT+vehicleWT[i];
                totalXD = totalXD+vehicleXD[i];

                if (vehicleTypes[i] == "EV") {
                    totalEV_WT = totalEV_WT+vehicleWT[i];
                    totalEV_XD = totalEV_XD+vehicleXD[i];
                    evCount = evCount+1;
                }
                else if (vehicleTypes[i] == "PT") {
                    totalPT_WT = totalPT_WT+vehicleWT[i];
                    totalPT_XD = totalPT_XD+vehicleXD[i];
                    ptCount = ptCount+1;
                }
                else if (vehicleTypes[i] == "NC") {
                    totalNC_WT = totalNC_WT+vehicleWT[i];
                    totalNC_XD = totalNC_XD+vehicleXD[i];
                    ncCount = ncCount+1;
                }
                else if (vehicleTypes[i] == "FV") {
                    totalFV_WT = totalFV_WT+vehicleWT[i];
                    totalFV_XD = totalFV_XD+vehicleXD[i];
                    fvCount = fvCount+1;
                }
            }
        }

        outFile << endl;

        outFile << "Total Vehicles: " << total_vehicles << endl;
        outFile << "Total EV: " << total_EV << " (including " << promotedVehicles << " promotions)" << endl;
        outFile << "Total PT: " << (total_PT - promotedVehicles) << " (" << promotedVehicles << " promoted)" << endl;
        outFile << "Total NC: " << total_NC << " (" << canceledVehicles << " canceled)" << endl;
        outFile << "Total FV: " << total_FV << endl;

        int avgWT = 0;
        if (vehicleCount > 0) {
            avgWT = totalWT / vehicleCount;
        }

        int avgXD = 0;
        if (vehicleCount > 0) {
            avgXD = totalXD / vehicleCount;
        }

        int avgEV_WT = 0;
        if (evCount > 0) {
            avgEV_WT = totalEV_WT / evCount;
        }

        int avgPT_WT = 0;
        if (ptCount > 0) {
            avgPT_WT = totalPT_WT / ptCount;
        }

        int avgNC_WT = 0;
        if (ncCount > 0) {
            avgNC_WT = totalNC_WT / ncCount;
        }

        int avgFV_WT = 0;
        if (fvCount > 0) {
            avgFV_WT = totalFV_WT / fvCount;
        }

        outFile << "Average WT (all): " << avgWT << endl;
        outFile << "Average WT (EV): " << avgEV_WT << endl;
        outFile << "Average WT (PT): " << avgPT_WT << endl;
        outFile << "Average WT (NC): " << avgNC_WT << endl;
        outFile << "Average WT (FV): " << avgFV_WT << endl;
        outFile << "Average XD: " << avgXD << endl;

        outFile << "Promoted vehicles: " << promoted_count << endl;
        outFile << "Canceled vehicles: " << canceled_count << endl;

        float promotedPercent = 0.0;
        if (total_PT > 0) {
            promotedPercent = (promoted_count * 100.0) / total_PT;
        }
        float canceledPercent = 0.0;
        if (total_vehicles > 0) {
            canceledPercent = (canceled_count * 100.0) / total_vehicles;
        }

        outFile << "% Auto-Promoted PT: " << promotedPercent << "%" << endl;
        outFile << "Signal Switches: " << 1 << endl;
        outFile << "% Vehicles Canceled: " << canceledPercent << "%" << endl;

       

        
       

       
        outFile.close();
        
    }

};




int main() {
    UI ui;

    ui.selectSimulationMode();

    ui.getFile();
    ui.printStatistics();
    ui.writeOutputFile();

}






