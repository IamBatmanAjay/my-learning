#include<iostream>
#include<queue>
using namespace std;

enum Direction {
    up,
    down,
};

enum State {
    idle,
    moving,
    stopped,
};

class Elevator
{
private:
    int currentFloor;
    Direction currentDirection = Direction::up;
    State currentState = State::idle;
    std::queue<Request> currentJobs;
    std::queue<Request> upPendingJobs;
    std::queue<Request> downPendingJobs;
public:
    Elevator();
    ~Elevator();
    void StartElevator()
    {
        while (1)
        {
            if (CheckIfJobs())
            {
                if (currentDirection == Direction::up)
                {
                    Request request = currentJobs.front();
                    currentJobs.pop();
                    ProcessUpRequest(request);
                    if (currentJobs.empty())
                    {
                        AddPendingDownJobsToCurrentJobs();
                    }
                }

                if (currentDirection == Direction::down)
                {
                    Request request = currentJobs.front();
                    currentJobs.pop();
                    ProcessDownRequest(request);
                    if (currentJobs.empty())
                    {
                        AddPendingUpJobsToCurrentJobs();
                    }
                }
            }
        }
    }

    void ProcessUpRequest(Request request) {
		// The elevator is not on the floor where the person has requested it i.e. source floor. So first bring it there.
		int startFloor = currentFloor;
		if (startFloor < request.GetExternalRequest().GetSourceFloor()) {
			for (int i = startFloor; i <= request.GetExternalRequest().GetSourceFloor(); i++) {
				try {
				sleep(1000);
				} catch (std::exception e) {
					// TODO Auto-generated catch block
					cout << "got an exception ...";
				}
				cout << "We have reached floor -- " + i);
				currentFloor = i;
			}
		}
		// The elevator is now on the floor where the person has requested it i.e. source floor. User can enter and go to the destination floor.
		cout << "Reached Source Floor--opening door");

		startFloor = currentFloor;

		for (int i = startFloor; i <= request.GetInternalRequest().GetDestinationFloor(); i++) {
			try {
				sleep(1000);
			} catch (std::exception e) {
				// TODO Auto-generated catch block
				cout << "Got an exception ...";
			}
			cout << "We have reached floor -- " + i);
			currentFloor = i;
			if (CheckIfNewJobCanBeProcessed(request)) {
				break;
			}
		}

	}

    void ProcessDownRequest(Request request) {

		int startFloor = currentFloor;
		if (startFloor < request.GetExternalRequest().GetSourceFloor()) {
			for (int i = startFloor; i <= request.GetExternalRequest().GetSourceFloor(); i++) {
				try {
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				cout << "We have reached floor -- " + i;
				currentFloor = i;
			}
		}

		cout << "Reached Source Floor--opening door";

		startFloor = currentFloor;

		for (int i = startFloor; i >= request.GetInternalRequest().GetDestinationFloor(); i--) {
			try {
				Thread.sleep(1000);
			} catch (std::exception e) {
				cout << "Got exception";
			}
			cout << "We have reached floor -- " + i;
			currentFloor = i;
			if (CheckIfNewJobCanBeProcessed(request)) {
				break;
			}
		}

	}

    bool CheckIfNewJobCanBeProcessed(Request currentRequest) {
		if (CheckIfJobs()) {
			if (currentDirection == Direction::up) {
				Request request = currentJobs.front();
				if (request.GetInternalRequest().GetDestinationFloor() < currentRequest.GetInternalRequest()
						.GetDestinationFloor()) {
					currentJobs.push(request);
					currentJobs.push(currentRequest);
					return true;
				}
				currentJobs.push(request);

			}

			if (currentDirection == Direction::down) {
				Request request = currentJobs.front();
				if (request.GetInternalRequest().GetDestinationFloor() > currentRequest.GetInternalRequest()
						.GetDestinationFloor()) {
					currentJobs.push(request);
					currentJobs.push(currentRequest);
					return true;
				}
				currentJobs.push(request);
			}

		}
		return false;

	}

	void AddPendingDownJobsToCurrentJobs() {
		if (!downPendingJobs.empty()) {
			currentJobs = downPendingJobs;
			currentDirection = Direction::down;
		} else {
			currentState = State::idle;
		}

	}

	void AddPendingUpJobsToCurrentJobs() {
		if (!upPendingJobs.empty()) {
			currentJobs = upPendingJobs;
			currentDirection = Direction::up;
		} else {
			currentState = State::idle;
		}
	}

    bool CheckIfJobs()
    {
        if (!currentJobs.empty()) return true;
        return false;
    }

    void AddJobs(Request request) {
		if (currentState == State::idle) {
			currentState = State::moving;
			currentDirection = request.GetExternalRequest().GetDirectionToGo();
			currentJobs.push(request);
		} else if (currentState == State::moving) {

			if (request.GetExternalRequest().GetDirectionToGo() != currentDirection) {
				AddtoPendingJobs(request);
			} else if (request.GetExternalRequest().GetDirectionToGo() == currentDirection) {
				if (currentDirection == Direction::up
						&& request.GetInternalRequest().GetDestinationFloor() < currentFloor) {
					AddtoPendingJobs(request);
				} else if (currentDirection == Direction::down
						&& request.GetInternalRequest().GetDestinationFloor() > currentFloor) {
					AddtoPendingJobs(request);
				} else {
					currentJobs.push(request);
				}

			}

		}

	}

	void AddtoPendingJobs(Request request) {
		if (request.GetExternalRequest().GetDirectionToGo() == Direction::up) {
			cout << "Add to pending up jobs";
			upPendingJobs.push(request);
		} else {
			cout << "Add to pending down jobs";
			downPendingJobs.push(request);
		}
	}

};

// The request made by the person from the floor when he requests for the elevator by 
// pressing either the UP or the DOWN button. It will have the fields enum Direction and integer sourceFloor.
class ExternalRequest
{
private:
    int sourceFloor;
    Direction directionToGo;
public:
    ExternalRequest(Direction dir)
    {
        directionToGo = dir;
    }
    ExternalRequest(/* args */);
    ~ExternalRequest();
    Direction GetDirectionToGo()
    {
        return directionToGo;
    }
    void SetDirectionToGo(Direction directionTogo)
    {
        directionToGo = directionTogo;
    }
    int GetSourceFloor()
    {
        return sourceFloor;
    }
};


// The Request made by person when he enters the elevator. The person presses the floor number to 
// which he wants to go. This will be the integer destinationFloor.
class InternalRequest
{
private:
    /* data */
    int sourceFloor;
    int destinationFloor;
public:
    InternalRequest();
    InternalRequest( int requestedFloor)
    {
        destinationFloor = requestedFloor;
    }
    ~InternalRequest();
    int GetSourceFloor(){
        return sourceFloor;
    }
    int GetDestinationFloor()
    {
        return destinationFloor;
    }
    void SetDestinationFloor(int requestedFloor)
    {
        destinationFloor = requestedFloor;
    }
};


// This class will be the encapsulation for the ExternalRequest and InternalRequest. 
// We will be passing this Request to the elevator to be processed. So this class will be 
// having two fields — ExternalRequest and InternalRequest.
class Request
{
private:
    InternalRequest mInternalRequest;
    ExternalRequest mExternalRequest;
public:
    Request(InternalRequest internalRequest, ExternalRequest externalRequest)
    {
        mExternalRequest = externalRequest;
        mInternalRequest = internalRequest;
    }   
    ~Request();
    ExternalRequest GetExternalRequest()
    {
        return mExternalRequest;
    }
    InternalRequest GetInternalRequest()
    {
        return mInternalRequest;
    }
    void SetExternalRequest(ExternalRequest externalRequest)
    {
        mExternalRequest = externalRequest;
    }
    void SetInternalRequest(InternalRequest internalRequest)
    {
        mInternalRequest = internalRequest;
    }
};



int main()
{
    int inputFloor;
    cin >> inputFloor;
    ExternalRequest er = ExternalRequest(Direction::up);
    InternalRequest ir =  InternalRequest(inputFloor);
    Request *req = new Request(ir, er);
    return 0;
}