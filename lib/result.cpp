#include <result.h>
#include <vec3.h>

#include <utility>

template<class result_type>
result<result_type>::result() 
    : content()
    , ok(false) {
}

template<class result_type>
result<result_type>::result(result_type _content)
    : content(_content)
    , ok(true) {
}

template<class result_type>
result<result_type>::result(result_type&& _content)
    : content(_content)
    , ok(true){
}

template<class result_type>
bool result<result_type>::is_ok() const{
    return this->ok;
}

template<class result_type>
result_type&& result<result_type>::unwrap(){
    if (this->ok){
        return std::move(this->content);
    }else{
        throw result_exception();
    }
}

template class result<math::vector::vec3>;
template class result<bool>;
