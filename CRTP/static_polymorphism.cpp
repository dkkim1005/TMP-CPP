#include <iostream>
#include <cmath>

template<class T>
struct base
{
	explicit base()
	: _y(0) {}

	void map_x_to_y(const double& x) {
		_y = static_cast<T*>(this) -> f(x);
	}

	void interface() const {
		static_cast<const T*>(this) -> implementation();
	}

	double get_y() const {
		return _y;
	}

protected:
	double _y;
};


struct derived : public base<derived>
{
	double f(const double& x) const {
		return std::pow(x, 2); 
	}

	void implementation() const {
		std::cout << "hello world" << std::endl;
	}
};


template<class T>
void check_hello(const base<T>& tester) {
	tester.interface();
}


template<class T>
void check_map(base<T>& tester, const double& x) {
	tester.map_x_to_y(x);
	std::cout << tester.get_y() << std::endl;
}


int main(int argc, char* argv[])
{
	derived obj;
	check_hello(obj);
	check_map(obj, 5);

	return 0;
}
