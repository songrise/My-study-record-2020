#lang sicp
(define (f x)
  (if (< x 3)
      x
      (+ (f (- x 1))
         (* 2 (f (- x 2)))
         (* 3 (f (- x 3))))))

(define (f-iter n)
	(define (f-iter-internal a b c count)
		(cond ((= count 0) (+ (* 3 a) (* 2 b) c))
					(else (f-iter-internal b c (+ (* 3 a) (* 2 b) c) (- count 1)))))
	(cond ((< n 3) n)
				(else (f-iter-internal 0 1 2 (- n 3)))))
