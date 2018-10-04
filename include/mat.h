
#include <array>
#include <stdexcept>
#include <string>
#include <utility>


namespace math {
    template <int n, typename object_type>
    class mat {
    protected:
        std::array<std::array<object_type, n>,n> _data;

    public:
        mat()
            : _data() {
        }

        ///
        /// \param data the rows of the matrix.
        ///
        mat(std::array<std::array<object_type, n>,n> data)
            : _data(data) {
       }

        mat(mat<n, object_type> &other)
            : _data(std::move(other._data)){
        }

        mat(mat<n, object_type>&& other)
            : _data(std::move(other._data)){
        }

        object_type& at(unsigned int col, unsigned int row){
            if(row >= n && col >= n) {
                throw std::out_of_range(std::string("tried to access an element, ") +
                    std::string("that is not an element of the matrix"));
            }
            return _data[row][col];
        }

        mat<n, object_type> operator*(mat<n, object_type> rhs) {
            mat<n, object_type> res{};

            for (unsigned int col = 0; col < n; col ++) {
                for(unsigned int row = 0; row < n; row++) {
                    for (unsigned int k = 0; k < n; k++){
                        res.at(col, row) += this->at(col, k) * rhs.at(k, row);
                    }
                }
            }
            return res;
        }
    };
}
