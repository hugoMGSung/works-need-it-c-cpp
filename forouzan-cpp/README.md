## 포르잔 C++ 학습

### 참조, 포인터

#### Reference 참조
- 참조는 객체의 또 다른 별칭이다
- 참조는 C++에 추가된 기능, 함수 등의 엔티티끼리 통신하는 것을 쉽게 도와줌

#### reference variable 참조변수
- 일반 변수와 다르게 메모리 위에 새로운 영역을 잡지 않음
- 단순하게 기존의 변수와 바인딩해서 기존의 변수에 새로운 이름을 붙여주는 것
    - 원본 변수가 있어야함 생성할 수 있다!

    ```cpp
    int score = 99;         // score변수 선언과 초기화
    int& rScore = score;    // rScore 선언과 score변수에 연결
    ```

- 참조 자료형과 변수 자료형은 일치해야 함
- 참조 변수에 단순값을 할당하는 것은 불가

- 참조 변수가 선언되고 변수와 연결되면 참조관계는 스코프를 벗어나 변수가 파괴되기 전까지 유지
    - 참조관계는 한 번 정의되면 변경불가
    - Constant relation : C++에서 변수와 참조변수 연결관계를 뜻함

    ```cpp
    int score2 = 100;
    int& rScore = score2;   // Error!!

    rScore = score2;        // Correct!!
    ```

- 참조관계가 만들어지면 원본변수와 참조변수 무엇을 사용해도 값을 가져올 수 있음

- 다중 참조 - 하나의 변수를 여러개의 참조변수와 바인딩 가능

    ```cpp
    int num = 100;
    int& rNum1 = num;
    int& rNum2 = num;
    int& rNum3 = num;
    ```

#### 값 변경
|번호|데이터변수|참조변수|상태|
|--:|:--|:--|:--:|
|1|int name = value;|int& rName = name;| 가능|
|2|const int name = value;|int& rName = name;|오류|
|3|int name = value;|const int& rName = name;|가능|
|4|const int name = value;|const int& rName = name;|가능|

1. 원본 데이터변수와 참조 변수에서 무엇을 사용해도 메모리 위치의 값 변경 가능
2. 오류 발생. const 한정자가 붙이 않은 참조변수에 const 한정자가 붙은 변수를 바인드하면 컴파일 오류 발생
3. 원본 데이터 변수를 사용 값을 변경할 수 있지만, 참조 변수로는 값 변경 불가
4. 원본, 참조변수 모두 값 확인 가능. 변경은 불가

#### 참조 활용
- pass by reference : 참조를 홀용 데이터를 전달하는 것
- return by reference : 데이터 리턴을 참조로 리턴하는 것

    ```cpp
    void passIt(int);

    int main() {
        int num = 100;
        passIt(num);
        return 0;
    }

    // pass-by-value
    void passIt(int num) {
        // TODO
    }
    ```

    ```cpp
    void passIt(int&);

    int main() {
        int num = 100;
        passIt(num);
        return 0;
    }

    // pass-by-reference
    void passIt(int& rNum) {
        // TODO
    }
    ```

##### 값 전달의 특징
- 값으로 전달은 호출하는 함수 쪽의 값이 호출되는 함수쪽의 변수로 복사
- 값으로 전달은 인수와 매개변수가 독립적으로 존재
- 매개변수를 변경하는 일이 인수를 변경하는 일에 영향을 주지 않음
- 복사 비용 발생
- 복사 대상 객체가 크다면, 인수를 매개변수로 복사할 때 많은 비용이 생성
- 기본 자료형을 복사할때는 문제가 없지만 클래스 자료형 등 크기가 큰 자료형 복사시 방법고려 필요

##### 참조 전달의 특징
- 참조로 전달은 원본 변수와 매개변수가 동일한 객체. 메모리를 추가 할당하지 않음
- const 한정자를 붙이지 않았으면 매개변수를 조작하는 행위가 인수를 조작하는 행위와 동일
- 복사 비용발생하지 않으며 큰 객체를 전다할 때 고려해야 함

    ```cpp
    void fork(int& rX) { }

    fork(5); // Compile error
    ```