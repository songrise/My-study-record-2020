#lang sicp

(define (fold-left op init seq)
               (define (iter result rest)
                 (if (null? rest)
                     result
                     (iter (op result (car rest))
                           (cdr rest))))
               (iter init seq))

(define x (list 1 2 3 4 5))


(define (reverse list)
  (fold-left (lambda(x y) (cons y x)) nil  list))


(reverse x)



;fold-right version:
(define (accumulate op init seq) ;return accumulated sequence concatenated by given op
  (if (null? seq)
      init
      (op (car seq) (accumulate op init (cdr seq)))))

(define (reverse2 seq)
  (accumulate (lambda (x y) (append y (list x)))  nil seq))

(reverse2 x)