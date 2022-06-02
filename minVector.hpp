#include <memory>

namespace ft {
	template<typename Data>
	class vector {
		size_t	d_size;
		size_t	d_capacity;
		Data	*d_data;

		public:
			vector() : d_size(0), d_capacity(0), d_data(0) {};
			vector(vector const &other) {*this = other;};
			~vector() {free(d_data);};
			vector &operator=(vector const  &other) {
				free(d_data);
				d_size = other.d_size;
				d_capacity = other.d_capacity;
				d_data = (Data *)malloc(d_capacity * sizeof(Data));
				memcpy(d_data, other.d_data, d_size * sizeof(Data));
				return *this;
			};
			void push_pack(Data const &x) {
				if (d_capacity == d_size)
					resize();
				d_data[d_size++] = x;
			};
			size_t size() const  {return d_size;};
			Data const &operator[](size_t id) const {return d_data[id];};
			Data &operator[](size_t id) {return d_data[id];};

		private:
			void resize() {
				d_capacity = d_capacity ? d_capacity * 2 : 1;
				Data	*newdata = (Data *)malloc(d_capacity * sizeof(Data));
				memcopy(newdata, d_data, d_size * sizeof(Data));
				free(d_data);
				d_data = newdata;
			}

	}
}
