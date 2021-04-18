#include <iostream>
#include <iomanip>
#include <string>
#include "base.h"

namespace Base {

	/// �������� ������������
	base::base() : base(0) {
	}
	base::base(size_t rnc) : base(rnc, rnc) {
	}
	base::base(size_t Row, size_t Col) : row(Row), col(Col) {
		if (Row == 0 || Col == 0) {
			mass = nullptr; row = 0; col = 0;
		}
		else
			mass = new double[row * col]();
	}
	base::base(const base& obj) : row(obj.row), col(obj.col) {
		std::copy(obj.mass, obj.mass + row * col, mass);
	}
	base::base(base&& obj) noexcept : row(obj.row), col(obj.col), mass(nullptr)  {
		std::swap(mass, obj.mass);
	}
	///

	//�������
	matrix::matrix() : base(0) {
	}
	matrix::matrix(size_t rnc) : base(rnc, rnc) {
	}
	matrix::matrix(size_t Row, size_t Col) : base(Row, Col){
	}
	matrix::matrix(const matrix& obj) : base(obj) {
	} 
	matrix::matrix(matrix&& obj) noexcept : base(obj) {
	}
	matrix::matrix(const base& obj) : base(obj) {

	}
	matrix::~matrix()  {
		delete[] mass;
	}

	// �������
	vector::vector(): base(0) {
	}
	vector::vector(size_t col) : base(1,col) {
	}
	vector::vector(const vector& obj): base(obj) {
	}
	vector::vector(vector&& obj) noexcept : base(obj) {
	}
	vector::vector(const base& obj) : base(obj) {

	}
	vector::~vector() {
		delete[] mass;
	}
	double vector::operator[](size_t ind) const {
		if(ind >= 0 || ind < this->col)
			return mass[ind];
	}
	double& vector::operator[](size_t ind) {
		if (ind >= 0 || ind < this->col)
			return mass[ind];
	}



	base::massRow::massRow(const base* obj, size_t R) :
		row(R* obj->row),
		Array(obj) {
	}
	base::massRow::massRow(base* obj, size_t R):
		row( R*obj->row),
		Array(obj){
	}
	double base::massRow::operator[](size_t ind) const { return Array->mass[row + ind]; }
	double& base::massRow::operator[](size_t ind) { return Array->mass[row + ind]; }
		
	base::massRow base::operator[](size_t ind) { return massRow(this, ind); }
	const base::massRow base::operator[](size_t ind) const { return massRow(this, ind); }



	std::string matrix::GetType() const {
		return "matrix";
	}
	std::string vector::GetType()const {
		return "vector";
	}




	base& base::operator+=(const base& obj) {
		if (this->GetType() == "matrix" && obj.GetType() == "vector") {
			if (this->col == obj.col) {
				for (int i = 0; i < this->col; i++)
					this->mass[i] += obj.mass[i];
				return *this;
			}
		}
		else if(this->GetType() == "vector" && obj.GetType() == "matrix"){
			return *this;
		}
		else {
			if (this->check_sub(obj)) {
				for (int i = 0; i < this->col; i++)
					for (int j = 0; j < this->row; j++)
						this->mass[i * this->row + j]+=obj.mass[i*obj.row+j];
				return *this;
			}
		}
	}

	base& base::operator-=(const base& obj) {
		if (this->GetType() == "matrix" && obj.GetType() == "vector") {

			return *this;
		}
		else {
			return *this;
		}
	}


	base& base::operator*=(const base& obj) {
		if (this->GetType() == "matrix" && obj.GetType() == "vector") {

			return *this;
		}
		else {
			return *this;
		}
	}

	base& base::operator*=(const double item) {
		for (int i = 0; i < this->row * this->col; i++)
			this->mass[i]*=item;
		return *this;
	}
	
	matrix operator+(const base& fobj, const base& sobj) {
		if (fobj.GetType() != "vector")
			return matrix(fobj) += sobj;
		else
			return matrix(sobj) += fobj;
	}
	matrix operator-(const base& fobj, const base& sobj) {
		if (fobj.GetType() != "vector")
			return matrix(fobj) -= sobj;
		else
			return matrix(sobj) -= fobj;
	}
	matrix operator*(const base& fobj, const base& sobj) {
		if (fobj.GetType() != "vector")
			return matrix(fobj) *= sobj;
		else 
			return matrix(sobj) *= fobj;
	}
	matrix operator*(const matrix& obj, const double item) {
		return matrix(obj) *= item;
	}
	matrix operator*(const double item, const base& obj) {
		return matrix(obj) *= item;
	}
	std::ostream& operator<<(std::ostream& out, const matrix& obj) {
		int Width = out.width();
		for (int i = 0; i < obj.col; i++) {
			for (int j = 0; j < obj.row; j++) {
				out << std::setw(5) << obj.mass[i*obj.col + j];
			}
			out << std::endl;
		}
		return out;
	}



	vector operator+(const vector& fobj, const vector& sobj) {
		return vector(fobj) += sobj;
	}
	vector operator-(const vector& fobj, const vector& sobj) {
		return vector(fobj) -= sobj;
	}
	vector operator*(const vector& obj, const double item) {
		return vector(obj) *= item;
	}
	vector operator*(const double item, const vector& obj) {
		return vector(obj) *= item;
	}
	std::ostream& operator<<(std::ostream& out, const vector& obj) {
		int Width = out.width();
		for (int i = 0; i < obj.col; i++) {
			out << std::setw(5) << obj.mass[i];
		}
		return out;
	}


	bool base::check_sub(const base& obj) {
		if (this->GetType() == "vector" && obj.GetType() == "vector") {

		}
		else if(this->GetType() == "matrix" && obj.GetType() == "matrix") {

		}
		else if(this->GetType() == "matrix" && obj.GetType() == "vector") {

		}
		else {

		}
		return false;
	}
	bool base::check_mul(const base& obj) {
		if (this->GetType() == "vector" && obj.GetType() == "vector") {

		}
		else if (this->GetType() == "matrix" && obj.GetType() == "matrix") {

		}
		else if(this->GetType() == "matrix" && obj.GetType() == "vector") {

		}
		return false;
	}
}
