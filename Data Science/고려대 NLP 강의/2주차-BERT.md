# 2주차

## 1교시: 딥러닝 개관

### 딥러닝의 문제들

1. 과적합 (Overfitting)

2. 기울기 소실 (Vanishing Gradient)

### 과적합



### 기울기 소실

**기울기 소실(Vanishing Gradient) and 활성함수(Activation Function)** 

- 최적화(또는 오차역전파) 과정에서 가중치 행렬이 업데이트되지 못하고 퍼셉트론의 노드가 죽어버리는 현상. 따라서 모델의 일반화(예측) 능력에 한계 발생.

- 최적화 기법 : **Optimizer = ‘Adam’**

- Logistic Regression
  - 0과 1로 판단
  - S자  그래프
- XOR 문제
  - AND와 OR는 가능하지만,
  - XOR는 단순한 직선으로 구분 지을 수 없다.
  - 해결법은 MLP! 공각은 왜곡(2차원을 3차원으로, 즉 차원을 늘린다.)

- Multi Layer Perceptron(MLP)
  - 레이어가 많기 때문에 '딥'러닝이라 한다.
- Activation Function
  - 판단하는 함수
  - 1 또는 0 (Yes or No)
  - 일반적인 딥러닝의 아키텍쳐 : sigmoid

### 

## 2교시 : 한국어 임베딩 4장 : BERT 구동해보기

### 목차

- 단어 단위 임베딩 : word-embedding
  - King-man + Woman = ? : word2vec
  - assume과 assumpton 그렇게 다른가요? : FastText
  - 주변 단어만 고려한다고요? : Glove

- 문장 단위 임베딩 : laguage model
  - BERT의 탄생 : RNN ~ Transfromer 
  - Attention is all you need
  - BERT의 구조와 쓰임



### One-Hot encoding

-예시 : 세상 모든 사람

​	[1, 0, 0] : 세상

​	[0, 1, 0] : 모든

    [0, 0, 1] : 사람

- 단점 : 단어 사이의 유사도 측정을 못함 ( 의미를 부여하기 힘들다 )
  - 단어 사이의 모든 각도가 90도이기 때문에 코사인 유사도를 사용하기 어렵다.
- One-Hot vector를 압축해서 Embedding vector를 구해서 문제를 해결함

### 무슨 정보를 이용해 단어를 표현할 건지?

- 주변단어 : word2vec
- 주변단어+n-gram : FastText
- 주변단어+분포 : Glove

### Word2Vec

- 어떤 정보를 담는지
  - 주변 단어를 고려하여 모르는 내용을 유추 가능하다.
  - Target word : 찾을 단어
  - context word : target word를 찾을 수 있는 문맥에 속한 단어
  - window size : context word 중 target word 주변의 단어를 몇 개 볼지

- 구조
  - input layer
  - hidden layer
  - output layer
    - 학습을 하는 단계

- 종류
  - CBOW
    - 여러개의 context words를 사용하여 하나의 target word 예측
  - skip-gram : 대부분 이 모델을 사용한다.
    - target word로 여러개의 context word 예측
    - 여러개의 데이터가 생성되기 때문에 더 정확한다.

- 장단점
  - 장점
    - 단어간 유사도 측정
    - 단어간 관계 파악
    - 벡터 연산을 통한 추론
  - 단점
    - 단어의 subword information 무시
      - 서울시와 서울역 간의 관계를 모름
    - Out of vocabulary

### Fast Text

- subword information을 고려
- 단어를 n-gram 으로 나누어 학습
- 예시 : Orange와 Oranges

​	

### 주변 단어만 봐도 충분할까?

- 전체 코퍼스의 통계 정보를 고려

- Glove로 해결



### Glove

- word2vec이 전체 corpus의 정보를 담지 못한다는 문제
- 두 단어의 유사도에 통계 정보가 반영

- 내적을 통한 동시 등장 확률



### 실습

- gensim 라이브러리 사용
  - word2vec, FastTest등 함수 내장  



## 3교시 : BERT 등장의 배경 Transformer Network

### BERT의 등장 배경

- 등장 순서 : 

Bag of words 가정 > 전통적 언어모델 > NNLM > RNN > LSTM >Seq2Seq >Attention > Tranformer > BERT

- 기본 철학 복습
  - 빈도
  - 순서
  - 분포
- Bag of words 기법 
  - 단어의 등장 순서와 관계 없이 
     문서 내 단어의 **등장** **빈도를** **임베딩으로** 쓰는 기법
  - 언어를 독립사건이라고 가정을 했기 때문에 문제
- 전통적 언어 모델
  - 언어 모델이란? 단어 시퀀스에 확률을 부여한 모델
  - 통계 기반 언어 모델
  - 단점 : 
    - 희소문제 (학습 데이터 한계)
    - 장거리 의존 못함(long-range dependency problem)
    - 단어간 유사도 계산 어려움(이후 분포가정으로 발전)

- NNLM

  - Neural Network Language Model (신경망으로 만든 언어 모델)

  - 단어간 유사도를 학습

### Transformer Network

트랜스포머는 RNN을 사용하지 않지만
 기존의 seq2seq처럼 인코더에서 입력 시퀀스를 입력받고, 디코더에서 출력 시퀀스를 출력하는 **인코더-디코더** **구조를** **유지하고** 있습니다. 다만 다른 점은 인코더와 디코더라는 단위가 **N개가** 존재할 수 있다는 점입니다.

1. Scaled Dot-Product Attention
2. Multi-Head Attention
3. Position-wise Feedforward Networks
4. 트랜스포머의 학습 전략



## 4교시 : BERT 실습

준비

데이터로드

전처리 - 훈련셋 : input형식, 토크나이징

딥러닝 모델 생성 : text => 숫자 (padding)

모델 학습 (Train &validation)

모델 평가

- 영화 후기 내용으로 실습