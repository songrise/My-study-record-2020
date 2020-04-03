#lang sicp
(define (facRecur x)
  (if (= x 1)
      1
      (* x (facRecur (- x 1)))))

(define (fact n)
  (fac-iter 1 1 n))

(define (fac-iter p i max)
  (if (> i max)
  p
  (fac-iter (* i p) (+ i 1) max)))
  