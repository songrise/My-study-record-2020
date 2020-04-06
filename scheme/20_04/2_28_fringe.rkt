#lang sicp


(define x (list (list 1 2) (list 3 4)))

(define (fringe tree)
  (cond ((null? tree) nil)
        
        ((not (pair? tree)) (list tree)) ; it is a leaf
        
        (else (append (fringe (car tree)) (fringe (cdr tree))))))
        ;change the invocation order(cdr before car), we can get reversed answer.

(fringe x)
(fringe (list x x))