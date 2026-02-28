//pg 753 or sumn. Don't forget you 
//#include <iostream>
//using namespace std;

int main() {
	class cashRegister {
	public:
		int getCurrentBalance() const;
		void acceptAmount(double amountIn);
		cashRegister(int cashIn = 500);  //I have no idea what cash in is.

	private:
		int cashOnHand;
	};
}

int cashRegister::getCurrentBalance() {
	return cashOnHand const;
}