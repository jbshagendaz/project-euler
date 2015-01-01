
; my solution
; (println (keep #(if (or (zero? (mod % 3)) (zero? (mod % 5))) %) (range 1000)))

; online solution
; (apply + (filter #(zero? (min (mod % 5) (mod % 3))) (range 1000)))

; more elegant solution
(reduce + (set (concat (range 0 1000 3) (range 0 1000 5))))