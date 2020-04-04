#lang sicp

(define (func1 x)
  (+ (* x x x) (* 3 (* x x)) 2)) 

(define (abs x) 
(if (< x 0)
(- x)
(x)))

(define (goodEnough? x y)
(< (abs (- x y)) 0.001))


(define (avg x y)
(/ (+ x y) 2))

(define (findroot f a b)
  (let((fa (f a))
      (fb (f b))
      (mid (avg a b)))

    
      (if(goodEnough? fa fb)
         mid
      (let ((test (f mid)))
        (cond ((< test 0) (findroot f mid b))
               ((> test 0) (findroot f a mid))
         (else mid))
      )
      )
      )
)

  
