#lang sicp

(define x (list 1 2 3 4 5 6 7))

(define (map proc items)
  (if (null? items)
      nil
      (cons (proc (car items))
      (map proc (cdr items)))))


(define (scale-x x items)
  (map (lambda (y) (* x y))
       items))