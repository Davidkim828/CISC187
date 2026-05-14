# Stacks and Queues

## 1. Stack `S[1..6]`

Initially empty:

`[ _, _, _, _, _, _ ]`

- `PUSH(S,4)` → `[ 4, _, _, _, _, _ ]`
- `PUSH(S,1)` → `[ 4, 1, _, _, _ , _ ]`
- `PUSH(S,3)` → `[ 4, 1, 3, _, _, _ ]`
- `POP(S)` → `[ 4, 1, _, _, _, _ ]`
- `PUSH(S,8)` → `[ 4, 1, 8, _, _, _ ]`
- `POP(S)` → `[ 4, 1, _, _, _, _ ]`

Final stack:  
`[ 4, 1, _, _, _, _ ]`

---

## 2. Queue `Q[1..6]`

Initially empty:

`[ _, _, _, _, _, _ ]`

- `ENQUEUE(Q,4)` → `[ 4, _, _, _, _, _ ]`
- `ENQUEUE(Q,1)` → `[ 4, 1, _, _, _, _ ]`
- `ENQUEUE(Q,3)` → `[ 4, 1, 3, _, _, _ ]`
- `DEQUEUE(Q)` → `[ _, 1, 3, _, _, _ ]`
- `ENQUEUE(Q,8)` → `[ _, 1, 3, 8, _, _ ]`
- `DEQUEUE(Q)` → `[ _, _, 3, 8, _, _ ]`

Final queue:  
`[ _, _, 3, 8, _, _ ]`

---

## 3. ENQUEUE and DEQUEUE with overflow / underflow detection

### ENQUEUE(Q, x)
- If queue is full, report **overflow**
- Otherwise insert `x` at the rear

### DEQUEUE(Q)
- If queue is empty, report **underflow**
- Otherwise remove and return the front element

---

## 4. Four O(1) deque procedures using an array

### InsertFront(x)
- If full, report overflow
- Move `front` backward circularly
- Insert `x` at `front`

### InsertRear(x)
- If full, report overflow
- Move `rear` forward circularly
- Insert `x` at `rear`

### DeleteFront()
- If empty, report underflow
- Remove element at `front`
- Move `front` forward circularly

### DeleteRear()
- If empty, report underflow
- Remove element at `rear`
- Move `rear` backward circularly
