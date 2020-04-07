#lang sicp
;modularized sequence pack, see SICP(chinese 2ed) p.77.

(define (enumerate_tree tree) ;return list of all leaves
  (cond ((null? tree) nil)
        ((not (pair? tree)) (list tree))
        (else (append (enumerate_tree (car tree))
                      (enumerate_tree (cdr tree))))))

(define (filter pred seq) ;return filtered sequence (under given predicate)
  (cond ((null? seq) nil)
        ((pred (car seq)) (cons (car seq) (filter pred (cdr seq))))
        (else  (filter pred (cdr seq)))))

(define (map proc seq) ;return mapped sequence.
  (if (null? seq)
      nil
      (cons (proc (car seq))
      (map proc (cdr seq)))))

(define (accumulate  op init seq) ;return accumulated sequence concatenated by given op
  (if (null? seq)
      init
      (op (car seq (cdr seq)))))

; end of sequence packet

(define (square x) (* x x))

(define (sum_odd_squares tree)
  (accumulate + 0 (map square (filter odd? tree))))

(sum_odd_squares (list(list 1 3) (list 7 2)))