# 소프트웨어 개발

## 데이터 입,출력 구현


## 통합 구현


## 제품 소프트웨어 패키징



## 애플리케이션 테스트관리

### 통합테스트(Integration Test)
통합 테스트는 단위 테스트가 끝난 모듈을 통합하는 과정에서 발생하는 오류 및 결함을 찾는 테스트 기법이다.

#### 하향식 통합테스트(Top Down Integration Test)
하향식 통합 테스트는 프로그램의 상위 모듈에서 하위 모듈 방향으로 ㅌ오합하면서 테스트하는 기법이다.

- 테스트 초기부터 사용자에게 시스템 구조를 보여줄 수있다.
- 상위 모듈에서는 테스트 케이스를 사용하기 어렵다.
- 절차
    - 주요 제어 모듈은 작성된 프로그램을 사용하고, 주요 제어 모듈의 종속 모듈들은 스텁(STUB)으로 대체한다.
    - 깊이 우선 또는 넓이 우선 등의 통합 방ㅅ기에 따라 하위 모듈인 스텁들이 한번에 하나씩 실제 모듈로 교체된다.
    - 모듈이 통합될 때마다 테스트를 실시한다.
    - 새로운 오류가 발생하지 않음을 보증하기 위해 회귀 테스트를 실시한다.

#### 상향식 통합 테스트(Bottom Up Integration Test)
상향식 통합 테스트는 프로그램의 하위 모듈에서 상위 모듈 방향으로 통합하면서 테스트하는 기법이다.

- 가장 하위 단계의 모듈부터 통합 및 테스트가 수행되므로 스텁은 필요하지 않지만, 하나의 주요 제어 모듈과 관련된 종속 모듈의 그룹인 클러스터가 필요하다.
- 절차
    - 하위 모듈을 클러스트로 결합한다.
    - 상위 모듈에서 데이터의 입,출력을 확인하기 위해 더미 모듈인 드라이버를 작성한다.
    - 통합된 클러스터 단위로 테스트한다.
    - 테스트가 완료되면 클러스터는 프로그램 구조의 상위로 이동하여 결합하고 드라이버는 실제 모듈로 대체된다.



> 테스트 스텁(Test Stub)
제어 모듈이 호출하는 타 모듈의 기능을 단순히 수행하는 도구로, 일시적으로 필요한 조건만을 가지고 있는 시험용 모듈입니다.

> 테스트 드라이버(Test Driver)
테스트 드라이버는 테스트 대상의 하위 모듈을 호출하고, 파라미터를 전달하고, 모듈 테스트를 수행 후의 결과를 도출하는 도구입니다.

> [Differences betwen test stub and test driver](https://www.quora.com/What-is-the-difference-between-stubs-and-drivers-in-software-testing)
>
> Stubs are dummy modules that always used to simulate the low level modules.
>
>Stubs are the called programs.
>
>Stubs are used when sub programs are under construction.
>
>Stubs are used in top down approach
>
>Drivers are dummy modules that always used to simulate the high level modules.
>
>Drivers are the calling programs.
>
>Drivers are only used when main programs are under construction.
>
>Drivers are used in bottom up integration.





## 인터페이스 구현