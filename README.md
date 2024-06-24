# 5-Stage Pipelined CPU Simulator

## 프로젝트 개요

이 프로젝트는 컴퓨터 구조의 핵심 개념인 5단계 파이프라인 CPU를 C++로 구현한 시뮬레이터입니다. MIPS 아키텍처를 기반으로 하며, 실제 하드웨어의 동작을 소프트웨어로 정확히 모델링하였습니다. 이 시뮬레이터는 컴퓨터 구조의 이론적 이해를 실제 구현으로 연결하는 과정을 보여줍니다.

## 주요 기능

1. **5단계 파이프라인 구현**
   - Instruction Fetch (IF)
   - Instruction Decode (ID)
   - Execute (EX)
   - Memory Access (MEM)
   - Write Back (WB)

2. **MIPS 명령어 세트 지원**
   - 산술 연산: add, sub, addi
   - 논리 연산: and, or, nor
   - 비교 연산: slt (Set on Less Than)
   - 메모리 접근: lw (Load Word), sw (Store Word)
   - 분기 명령: beq (Branch if Equal)

3. **데이터 포워딩**
   - EX-EX 포워딩
   - MEM-EX 포워딩
   - MEM-MEM 포워딩

## 기술 스택

- 언어: C++17
- 빌드 도구: Make

## 프로젝트 구조
```
.
├── tests/
│   ├── test
├── ALU.h
├── ALUControl.h
├── Control.h
├── DigitalCircuit.h
├── Makefile
├── Memory.h
├── Miscellaneous.h
├── PipelinedCPU.h
├── README.md
├── RegisterFile.h
└── testAssn4.cc
```

## 주요 컴포넌트

1. **ALU (ALU.h)**: 산술 논리 연산을 수행합니다.
2. **Control Unit (Control.h)**: 명령어 해독 및 제어 신호 생성을 담당합니다.
3. **Register File (RegisterFile.h)**: CPU 레지스터를 모델링합니다.
4. **Memory (Memory.h)**: 명령어 메모리와 데이터 메모리를 시뮬레이션합니다.
5. **Pipelined CPU (PipelinedCPU.h)**: 전체 파이프라인 CPU의 동작을 구현합니다.


## 실행 방법

1. 프로젝트 클론:
```
git clone https://github.com/jongheon1/pipelined-cpu.git
cd pipelined-cpu
```

2. 빌드 및 테스트 실행:
```
//valina pipelined cpu
make clean && make testAssn4V1

./testAssn4V1 0 ./tests/ex1_regFile ./tests/ex1_instMemFile ./tests/ex1_dataMemFile 16

./testAssn4V1 0 ./tests/ex2_regFile ./tests/ex2_instMemFile
./tests/ex2_dataMemFile 20

//data forwarding
 make clean && make testAssn4V2

 ./testAssn4V2 0 ./tests/ex3_regFile ./tests/ex3_instMemFile ./tests/ex3_dataMemFile 15
```

## 학습 및 개선 사항

이 프로젝트를 통해 다음과 같은 역량을 개발/향상시켰습니다:

1. 복잡한 시스템의 객체 지향적 모델링
2. 성능 최적화 기법 적용
3. 체계적인 테스트 케이스 설계 및 구현

<!-- ## 관련 프로젝트

이 프로젝트의 경험은 다음과 같은 백엔드 개발 역량과 연결됩니다:

1. **복잡한 비즈니스 로직 구현**: CPU 파이프라인의 복잡한 로직 구현 경험은 복잡한 비즈니스 로직을 다루는 백엔드 시스템 개발에 직접적으로 적용될 수 있습니다.
2. **성능 최적화**: 비트 연산 최적화 및 메모리 관리 경험은 대규모 트래픽을 처리하는 백엔드 시스템의 성능 최적화에 활용될 수 있습니다.
3. **동시성 처리**: 파이프라인 단계의 병렬 처리 경험은 Spring의 비동기 처리 및 동시성 관리에 도움이 됩니다.
4. **테스트 주도 개발**: 체계적인 단위 테스트 및 통합 테스트 구현 경험은 백엔드 시스템의 안정성을 보장하는 테스트 주도 개발에 적용될 수 있습니다. -->
