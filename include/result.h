#pragma once

#include<exception>

///
/// This call stores results with an boolean flag, if the computation
/// was successfull or not.
///
/// example:
/// auto comp_result = some_computation();
/// if (comp_result.is_ok()) {
///     process(comp_result.unwrap());
/// } else {
///     do_something_else();
/// }
///
template<class result_type>
class result {

private:
    bool ok;
    result_type content;

public:
    result();
    result(result_type _content);
    result(result_type&& _content);

    bool is_ok() const;
    ///
    /// Throws an exception, if the result is failed.
    /// @returns The wrapped result
    ///
    result_type&& unwrap();
};

class result_exception : public std::exception{
    virtual const char* what() const throw() {
        return "tried to unwrap a failed result";
    }
};
