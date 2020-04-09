#lang sicp

(define (memq item x)
  (cond ((null? x) false)
        ((eq? item (car x))x)
        (else (memq item (cdr x)))))


(memq 'apple '(x (apple pear) y apple pear))

; this implementation suppose a and b are of same type.
(define (equal? a b)
  (cond ((and (not (pair? a)) (not (pair? b))) (eq? a b))
        (else (if (eq? (car a) (car b)) ;they are both list
              (equal? (cdr a) (cdr b))
              false))))

(equal? '(this is a list) '(this is a list))
(equal? 'a 'a)
(equal? '(a list) '(another list))