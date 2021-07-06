#include <iostream>
#include <thread>

using namespace std;

class A {
public:
    static void* sayHello(void *args) {
        cout << "hello" << endl;
        return NULL;
    }
};

int main() {
    thread t(A::sayHello, (void*)NULL);
	cout << "hello" << endl;

	return 0;
}