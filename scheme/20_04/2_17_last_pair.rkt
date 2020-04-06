#lang sicp


(define x (list 3 4 1 2 4 5 1 32))

(define (last_pair arr)
  (if (null? (cdr arr))
  (list (car arr))
  (last_pair (cdr arr))))

(last_pair x)