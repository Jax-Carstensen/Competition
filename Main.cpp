#include <iostream>
//#include <thread>
#include <fstream>

#include <chrono>

using namespace std;


bool isPrime(int n) {
	//Biggest performance improvement I could think of. First had i <= n / 2, but replace with i * i < n. Literally did more than the multithreading.
	if (n <= 0)
		return false;
	for (int i = 2; i * i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}


int main() {
	chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(
		chrono::system_clock::now().time_since_epoch()
	);
	/*const int threads = 4;
	thread* myThreads[threads];
	int toCount = 10000000;
	int add = toCount / threads;
	for (int j = 0; j < threads; j++) {
		myThreads[j] = new thread(t, j*add, (j+1) * add);
	}
	while (finished < threads) {
		continue;
	}
	for (int k = 0; k < threads; k++) {
		myThreads[k]->join();
	}
	for (int num = 0; num < currentIndex; num++) {
		outputFile << numbers[currentIndex] << endl;
	}*/
	ofstream outputFile("primes.txt");
	for (int i = 0; i < 1000000; i++) {
		if (isPrime(i)) {
			outputFile << i << endl;
		}
	}
	outputFile.close();
	chrono::milliseconds ms2 = chrono::duration_cast<chrono::milliseconds>(
		chrono::system_clock::now().time_since_epoch()
	);
	cout << "Total time: " << (ms2.count() - ms.count()) << " milliseconds." << endl;

	//Print all of the prime numbers between 1 and 1,000,000
	return 0;
}
