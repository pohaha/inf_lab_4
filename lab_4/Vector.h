#pragma once
#include <cstring>
#include <iostream>



class Double_Vector
{

private:
	double* data = nullptr;
	std::size_t length = 0;

public:
//method for resizing a vector
	void resize(const unsigned int& n_size, const double& n_element = 0)
	{
		double* n_data = new double[n_size];
		if (n_size < length)
			memcpy(n_data, data, n_size * sizeof(double));
		else
		{
			memcpy(n_data, data, length * sizeof(double));
			for (unsigned int i = length; i < n_size; i++)
				n_data[i] = n_element;
		}
		delete[] data;
		data = n_data;
		length = n_size;
	}
//method for checking if the vector is empty
	bool empty()
	{
		return (length == 0) ? (true) : (false);
	}
//this is a method for adding elements to the end of our vector
	void push_back(const double& n_data)
	{
		double* temp = new double[length + 1];

		std::memcpy(temp, data, sizeof(double) * length);
		delete[] data;

		data = temp;
		data[length++] = n_data;
	}
//this is a method for adding elements at the beginning of our vector
	void insert(const double& n_element)
	{
		double* temp = new double[++length];
		std::memcpy(&temp[1], data, sizeof(double) * (length-1));
		delete[] data;
		data = temp;
		data[0] = n_element;
	}

//method showing the first element of a vector
	double front()
	{
		return data[0];
	}

//method showing the last element of a vector
	double back()
	{
		return data[length - 1];
	}
//this method removes the element froim the end of a vector
	void pop_back()
	{
		double* n_data = new double[--length];
		memcpy(n_data, data, (length) * sizeof(double));
		delete[] data;
		data = n_data;
	}

//method for deleting an element at the specified index of a vector
	void erase(const unsigned int& index)
	{
		if (index >= length)
		{	
			std::cout << "unable to erase at that index!" << std::endl;
			return;
		}
		double* tmp = new double[length - 1];
		memcpy(tmp, data, index * sizeof(double));
		memcpy(&tmp[index], &data[index], (length - index - 1) * sizeof(double));
		delete[]data;
		data = tmp;
		length--;
	}

//clearing method
	void clear()
	{
		length = 0;
		delete[] data;
		data = nullptr;
	}

//swapping elements
	void swap(const unsigned int& id_1, const unsigned int& id_2)
	{
		double tmp = data[id_1];
		data[id_1] = data[id_2];
		data[id_2] = tmp;
	}
//this is a method for showing all contained elements
	void show(bool mode=true)
	{
		if(mode) std::cout << "array contents are: " << std::endl;
		for (unsigned int i = 0; i < length; i++)
		{
			if (mode) std::cout << "Element number " << i + 1 << " : ";
				std::cout << data[i] << '\t';
			if(mode)	std::cout<< std::endl;
		}

	}

//vector c-tors, d-tors
	//copy c-tor
	Double_Vector(const Double_Vector& target)
	{
		length = target.length;
		data = new double[length];
		std::memcpy(data, target.data, sizeof(double) * length);
	}
	//empty vector c-tor
	Double_Vector()
	{
	//this was used for tests
		//std::cout << "vector has been created - empty" << std::endl;
	}

	//c-tor with element initialization as a placeholder
	Double_Vector(std::size_t length, double placeholderElement): length(length)
	{
		data = new double[length];
		for (unsigned int i = 0; i < length; i++)
			data[i] = placeholderElement;
		//this was used for tests
			//std::cout << "vector has been created" << std::endl;
	}
		
	Double_Vector(double* n_Data, std::size_t n_Size):length(n_Size)
	{
		data = new double[length];
		std::memcpy(data, n_Data, length * sizeof(double));
	}
	//vector d-tor for cleaning the memory
	~Double_Vector()
	{
		delete[] data;
		//this was used for tests
			//std::cout << "vector has beed deleted" << std::endl;
	}


//tecnical vector operations
	// indexing operation
	double& operator[](unsigned int index)
	{
		if (index < length)
			return data[index];
		else
		{
			std::cout << "access violation - no such element yet" << std::endl;
			return data[0];
		}
	}
	const double& operator[](unsigned int index) const
	{
		if (index < length)
			return data[index];
		else
		{
			std::cout << "access violation - no such element yet" << std::endl;
			return data[0];
		}
	}

	void operator=(const Double_Vector& two)
	{
		length = two.length;
		double* n_data = new double[length];
		memcpy(n_data, two.data, sizeof(double) * length);
		data = n_data;		
	}

	
//usefull vector operations

	//summ of 2 equally-lengthed vectors
	Double_Vector operator+ (const Double_Vector& two)
	{
		if (length != two.length) {
			std::cout << "Error! sizes are mismatched!" << std::endl;
			return *this;
		}
		Double_Vector* outputVector=new Double_Vector(length,0.f);
		for (unsigned int i = 0; i < length; i++)
		{
			outputVector->data[i] = outputVector->data[i] + data[i] + two[i];
		}
		return *outputVector;
	};

	//vector-number multiplication
	Double_Vector operator* (double number)
	{
		Double_Vector* outputVector=new Double_Vector(length, 0.f);
		for (unsigned int i = 0; i <length; i++) {
			(*outputVector)[i] = (*outputVector)[i] + data[i] * number;
		}
		return *outputVector;
	};

	unsigned int getSize()
	{
		return length;
	}
	
};



