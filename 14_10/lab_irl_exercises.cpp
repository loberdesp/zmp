#include <algorithm>
#include <complex>
#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>

class TesterPodzialu {
    int dir;
public:
    explicit TesterPodzialu(int d) : dir(d) {}
    bool operator()(int value) {
        return value == dir;
    }
};

bool is_even(int value) {
    return value % 2 == 0;
}

// class Student {
//     float grade_avg;
// public:
//     explicit Student(float grade_avg) : grade_avg(grade_avg) {}
// };

void print_vector( std::vector<int> v) {
    for (auto x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

class Student {
public:
    explicit Student(int index) : index(index) {}
    int index;
};

void print_student_vector( std::vector<Student> v) {
    for (auto x : v) {
        std::cout << x.index << " ";
    }
    std::cout << std::endl;
}


int gen_5() {
    return 5;
}




int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6 ,5, 4, 3, 4, 5, 6, 3, 4, 5, 6};

    int desired_value = 3;

    int count = std::count(v.begin(), v.end(), desired_value);
    int even_count = std::count_if(v.begin(), v.end(), is_even);
    int countif_lambda = std::count_if(v.begin(), v.end(), [desired_value](int i) { return i == desired_value; });
    int countif_class = std::count_if(v.begin(), v.end(), TesterPodzialu(desired_value));

    std::cout << "Count :" << count << std::endl;
    std::cout << "Even count :" << even_count << std::endl;
    std::cout << "Count_if lambda:" << countif_lambda << std::endl;
    std::cout << "Count_if class:" << countif_class << std::endl;

    print_vector(v);
    std::sort(v.begin(), v.end());
    print_vector(v);
    std::sort(v.begin(), v.end(), [](int a, int b) { return a > b;});
    print_vector(v);

    std::vector<Student> students{Student(10), Student(20), Student(30)};

    print_student_vector(students);

    std::sort(students.begin(), students.end(), [](Student a, Student b) { return a.index < b.index;});

    print_student_vector(students);

    // Student thing doesn't work


    std::vector<int> v_gen;

    v_gen.resize(10);

    std::generate(v_gen.begin(), v_gen.end(), gen_5);

    print_vector(v_gen);int index;




    std::vector<int> v_full{1,2,3,4,5};

    std::vector<int> v_empty;

    // std::copy(v_full.begin(), v_full.end(), v_empty.begin());

    //on std::copy call we get segfault

    std::copy(v_full.begin(), v_full.end(), std::back_inserter((v_empty)));

    std::copy(v_full.begin(), v_full.end(), std::ostream_iterator<int>(std::cout , ", "));
    std::cout << std::endl;


    std::vector<int> va{1,2,3,4,5};
    std::vector<int> vb{6,7,8,9,10};

    std::vector<int> vTarget;
    vTarget.resize(5);

    std::transform(va.begin(), va.end(), vTarget.begin(), [](int x){ return x*x; });

    print_vector(vTarget);

    std::transform(va.begin(), va.end(), vb.begin(), vTarget.begin(), [](int a, int b){ return a+b; });

    print_vector(vTarget);


    std::vector<int> v_square{1,2,3};


    std::cout << std::accumulate(v_square.begin(), v_square.end(), 0, []( int sum, int x) {return sum + std::pow(x,2);}) << std::endl;




    return 0;
}