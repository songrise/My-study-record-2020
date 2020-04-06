#lang sicp


(define x (list 1 2 3 4 5 6 7))

;be cautious of type match
;in scheme, a list of one elem is (elem, nil) or to say it must be a pair.
;in short, list(1) == (cons 1 nil)


(define (reverse arr)
  (if (null? arr)
      nil
      (append (reverse (cdr arr)) (list (car arr)))))

(reverse x)