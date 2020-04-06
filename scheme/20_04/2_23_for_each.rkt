#lang sicp
(define (for_each op items)
  (if (null? items)
   nil
   ;this code is buggy
   ((op (car items))
   (for_each op (cdr items)))))
          


(for_each (lambda (x) (newline) (display x)) (list 1 2 3 4))