# 4. 프로그래밍 언어 활용

## 서버 프로그램 구현
## 프로그래밍 언어 활용
## 응용 SW 기초 기술 활용

### 인터넷

>IPv4 IPv6 차이점
- IPv4
    - 32bit (8bit x 4)
    - unicast/multicast/broadcast
- IPv6
    - 128bit (16bit x 8)
    - 기존  IPv4의 주소 부족 문제를 해결하기위해 개발
    - 인증성/기밀성/무결성 지원(= 보안 강화)
    - unicast/multicast/broadcast



### TCP/IP
TCP/IP는 인터넷에 연결된 서로 다른 기종의 컴퓨터들이 데이터를 주고받을 수 있도록 하는 표준 프로토콜이다.

TCP/IP는 다음과 같은 기능을 수행하는 TCP 프로토콜과 IP 프로토콜이 결합된 것을 의미한다.

- TCP
    - OSI 7계층의 전송 계층에 해당
    - 신뢰성 있는 연결형 서비스를 제고
    - 패킷의 다중화, 순서 제어, 흐름 제어 기능을 제공
    - 스트림 전송 기능 제공
    - TCP 헤더에는 Source/Destination Port Numer, Sequence Number, Acknowledgement Number, Checksum 등이 포함된다.
- IP
    - OSI 7계층의 네트워크 계층에 해당
    - 데이터그램을 기반으로 하는 비 연결형 서비스를 제공
    - 패킷의 분해/조립, 주소 지정, 경로 선택 기능을 제공
    - 헤더의 길이는 최소 20Byte에서 최대 60Byte이다.
    - IP 헤더에는 Version, Header Length, Total Packet Length, Header Checksum, Source IP Address, Destination IP Address등이 포함된다.