#pragma once
using namespace std;
namespace Base {
	class base
	{
	protected:
		double* mass;
		size_t row, col;

		base();
		base(size_t rnc);
		base(size_t row, size_t col);
		base(const base& obj);
		base(base&& obj)noexcept;
	
		class massRow {
		protected:
			const base* Array;
			size_t row;
		public:
			massRow(const base* obj, size_t R);
			double operator[](size_t R) const;
			massRow(base* obj, size_t R);
			double& operator[](size_t R);
		};
	public:
		massRow operator[](size_t ind);
		const massRow operator[](size_t ind) const;

		bool check_sub(const base& obj);
		bool check_mul(const base& obj);

		//\/\/
		base& operator+=(const base& obj);
		base& operator-=(const base& obj);
		base& operator*=(const base& obj);
		base& operator*=(const double item);		
		//\/\//

		virtual string GetType() const = 0;
	};
	
	class matrix : public base {
	protected:
		matrix(const base&);
	public:

		explicit matrix();
		explicit matrix(size_t);
		explicit matrix(size_t, size_t);
		matrix(const matrix&);
		matrix(matrix&&) noexcept;
		~matrix();
		friend ostream& operator<<(ostream& out, const matrix& obj);
		friend matrix operator+(const base& fobj, const base& sobj);
		friend matrix operator-(const base& fobj, const base& sobj);
		friend matrix operator*(const base& fobj, const base& sobj);
		friend matrix operator*(const matrix& obj, const double item);
		friend matrix operator*(const double item, const base& obj);

		virtual string GetType() const;
		
	};

	class vector : public base {
	protected:
		vector(const base&);
	public:

		explicit vector();
		explicit vector(size_t);
		vector(const vector&);
		vector(vector&&) noexcept;
		~vector();
		double operator[](size_t ind) const;
		double& operator[](size_t ind);
		friend ostream& operator<<(ostream&, const vector& obj);

		friend vector operator+(const vector& fobj, const vector& sobj);
		friend vector operator-(const vector& fobj, const vector& sobj);
		friend vector operator*(const vector& obj, const double item);
		friend vector operator*(const double item,	const vector& obj);


		virtual string GetType() const;
	};
}

